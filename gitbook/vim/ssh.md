# [轉]同時使用多個 Git 帳號
- http://finfin.github.io/2015/01/16/multiple-git-accounts.html

當你同時擁有兩個以上的 Git 帳號的時候，是怎麼切換帳號的呢？我曾經很手動的git config + 重新載入SSH Key，後來懶的這樣換來換去乾脆直接開 VM。
Git CLI 並不支援多重帳號，但我們可以透過 SSH 設定來達到多重帳號的功能。以下詳細步驟： （這些設定也適用於其他 Git 服務如 GitLab, BitBucket 等，把 github.com 修改成對應 host 即可）

#建立 SSH-KEY
（如果已經有 SSH-KEY 這段可以跳過，只要知道各帳號的 KEY 在哪就好）
假設擁有的帳號名稱分別是 ghWork 及 ghPersonal，對應的 email 為me@work 以及個人帳號 me@personal
```sh
$ cd ~/.ssh
$ ssh-keygen -t rsa -C "me@work"
# 把這個 key 存成 id_rsa_work
$ ssh-keygen -t rsa -C "me@personal"
```
# 把這個 key 存成 id_rsa_personal
這些指令會在 ~/.ssh 目錄下建立
- idrsapersonal
- idrsapersonal.pub
- idrsawork
- idrsawork.pub

# 新增你的 SSH-KEY
（如果已經登陸 SSH-KEY 這段可以跳過）
同個目錄下，複製 public key：
```sh
$ pbcopy < ~/.ssh/id_rsa_work.pub
```

如果你是用 GITHUB：
- 登入你的帳號
- 到 Account Settings
- 點擊 SSH Keys 然後 Add SSH Key
- 在輸入框內貼入剛剛複製的 KEY 然後點擊 Add Key 即可

重複這些步驟直到所有帳號的 KEY 都已經登錄。
# SSH 設定
黑魔法就在這裡，現在我們在 ~/.ssh 目錄底下建立一個名稱為config 的檔案，內容如下：
```sh
# 預設帳號 （個人帳號）
Host github.com
    HostName github.com
    User git
    IdentityFile ~/.ssh/id_rsa_personal

# 工作帳號
Host personal
   HostName github.com
   User git
   IdentityFile ~/.ssh/id_rsa_work

# 其他帳號
...
```
注意這裡我把個人帳號變成預設帳號，這是什麼意思？因為我把 Host是 github.com 的直接指到個人用的設定（KEY），當然也可以依照個人喜好把預設的換成其他帳號。
更新 SSH 設定
設定檔寫好之後就要更新 ssh agent

```sh
$ ssh-add -D
# 清除舊設定

$ ssh-add id_rsa_work
$ ssh-add id_rsa_personal
# 如有其他 key 在這裡繼續加入

$ ssh-add -l
# 看看 key 是不是都加入了

$ ssh -T github.com
Hi ghPersonal! You've successfully authenticated, but GitHub does not provide shell access.
$ ssh -T work
Hi ghWork! You've successfully authenticated, but GitHub does not provide shell access.
# 測試

```
# 新增 GIT REPO
```sh
# 工作目錄下
$ mkdir test-personal
$ cd test-personal

$ touch readme.md
# 隨便加個檔案

$ git init
$ git add .
$ git commit -am "first commit"
$ git remote add origin git@github.com:ghPersonal/test-personal.git
$ git push origin master
```

Push 成功就算大功告成！工作帳號也是類似指令。
注意：這裏假設把東西放在自己的 Repo 下，如果有使用 GIT Organization 的話，git@github.com:ghPersonal/test-personal.git 裡面的 ghPersonal 需要改成 Organization 名稱（或路徑）。
# 修改既有 REPO
如果有些現存的專案記得也要修改一下，專案的 .git/config 檔案儲存著 git 的設定資訊
```sh
[remote "origin"]
    url = git@github.com:ghWork/existing-project.git
    fetch = +refs/heads/*:refs/remotes/origin/*
```
原本的 config是這樣的，現在我們改成
``` sh
[remote "origin"]
    url = git@work:ghWork/existing-project.git
    fetch = +refs/heads/*:refs/remotes/origin/*
```
改動的地方只有一個，把 host (github.com) 改成 work，這樣就可以了。

完成這些設定之後，以後工作帳號就是 work 取代 github.com，而個人帳號不變（因為是預設）。這樣可以節省不少切換帳號的時間，就代表有更多時間可以專注在其他事情上。
