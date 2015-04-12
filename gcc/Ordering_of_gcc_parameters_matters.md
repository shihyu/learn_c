gcc參數順序
Ordering of gcc parameters matters

2013年最後一個月最後一個星期談一個奇怪的bug，我在嘗試pinfo的時候，configure腳本會提示ncurses有問題：

```
checking location of curses.h file... /usr/include/ncurses.h
checking if curses is usable... no
configure: error: Curses not found. You need curses to compile pinfo
```
打開config.log文件，發現這個提示：

```
configure:12563: checking if curses is usable
configure:12587: gcc -o conftest -g -O2 -I/usr/include    -L/usr/lib -lncurses conftest.c  >&5
/tmp/ccBLkSqd.o: In function `main':
/net/fantasia/home/zhanxw/software/pinfo-0.6.10/conftest.c:38: undefined reference to `initscr'
/net/fantasia/home/zhanxw/software/pinfo-0.6.10/conftest.c:39: undefined reference to `printw'
/net/fantasia/home/zhanxw/software/pinfo-0.6.10/conftest.c:40: undefined reference to `stdscr'
/net/fantasia/home/zhanxw/software/pinfo-0.6.10/conftest.c:40: undefined reference to `wrefresh'
/net/fantasia/home/zhanxw/software/pinfo-0.6.10/conftest.c:41: undefined reference to `stdscr'
/net/fantasia/home/zhanxw/software/pinfo-0.6.10/conftest.c:41: undefined reference to `wgetch'
/net/fantasia/home/zhanxw/software/pinfo-0.6.10/conftest.c:42: undefined reference to `endwin'
collect2: ld returned 1 exit status
```

從這個命令行來看，curses庫的頭文件目錄和庫文件目錄都對，但編譯的時候（鏈接/tmp/ccBLkSqd.o）卻找不到幾個函數的定義（比如：initscr，printw等等）。為了重現這個看起來不該出現的問題，我把conftest.c創建好，然後用相同的gcc命令行編譯代碼，的確是可以重現錯誤。

更令我不解的是如果把conftest.c放到命令行的末尾，這個編譯就能通過了：

```
# This does not work
gcc -o conftest -g -O2 -I/usr/include    -L/usr/lib -lncurses conftest.c 
# This works
gcc -o conftest conftest.c -g -O2 -I/usr/include    -L/usr/lib -lncurses  
```

為什麼把conftest.c移到「-L/usr/lib -lncurses」前面就能解決問題？
看到StackOverFlow上的一個帖子：

這個帖子講到gcc編譯和鏈接一個源程序時，會保留參數的順序，也就是說在鏈接時，把conftest.c放到前面和後面，效果不同。具體來講：

conftest.c 放到後面

```
gcc -o conftest -g -O2 -I/usr/include    -L/usr/lib -lncurses conftest.c 
<=> 等價於
gcc -o conftest -g -O2 -L/usr/lib -lncurses tmporary_object_file.o
conftest.c 放到前面
```

```
gcc -o conftest -g -O2 -I/usr/include conftest.c -L/usr/lib -lncurses 
<=> 等價於
gcc -o conftest -g -O2 tmporary_object_file.o -L/usr/lib -lncurses 
```

也就是說，gcc在鏈接目標文件時，會依照命令行的順序，對於每個在前面目標文件中沒有定義的函數，都試著在其後面的目標文件找找，如果最後一個目標文件也找不到，就報錯。因此在我們的例子裡，tmporary_object_file.o一定要放到-L/usr/lib -lncurses前面才能正確編譯。

回到本文最開始，我們如何讓configure把conftest.c放到「-L」前面？答案不是改動configure，而是使用LIBS環境變量：

```
LIBS="-L/usr/lib -lncurses" ./configure
```

與LIBS不同，LDFLAGS會放到conftest.c前面，這樣configure還是沒法正確的使用configure。

在本文最後，回想我們本來的問題，就是說gcc的參數有一定的順序要求。也許gcc的手冊裡寫了順序的要求，但是很少有人能夠看完gcc的手冊。如果見到類似問題，應該怎麼辦呢？我覺得可以有兩個思路，第一個就是想想寫gcc軟件的人是怎麼想的。比如現在gcc的選擇就是一個很方便的方法，如果當前沒某個函數沒有定義，就在他後面制定的目標文件裡找找。如果這個要求反過來，或者任何順序都支持，那麼鏈接的函數就會複雜（因為鏈接程序需要存儲所有定義過的函數，參見鏈接）；第二個就是想想傳統的（或者標準的）寫法是什麼，把已知的經驗和這個錯誤聯繫起來。比如configure的錯誤看起來很奇怪，但是先按照傳統的寫法先編譯後鏈接，找到一個能湊合工作的方案（把conftest.c放到前面），再逐步改變到出錯時的命令行，這個逐步的過程可以幫助查錯也能鞏固一下已有的知識。
