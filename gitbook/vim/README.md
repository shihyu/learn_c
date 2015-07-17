# VIM

- 安裝套件

```
sudo apt-get install git
```
- 建立資料夾


```
mkdir -p ~/.vim/bundle
cd ~/.vim/bundle

// 下載vundle 套件管理
git clone https://github.com/VundleVim/Vundle.vim
```


- ~/.vimrc

```
set nocompatible               " be iMproved
filetype off                   " required!
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#rc()
Bundle 'gmarik/Vundle.vim'
Bundle 'vim-scripts/L9'
Bundle 'vim-scripts/cscope_macros.vim'
Bundle 'scrooloose/nerdtree'
Bundle 'SirVer/ultisnips'
Bundle 'drmingdrmer/xptemplate'
Bundle 'vim-scripts/FuzzyFinder'
Bundle 'vim-scripts/AutoComplPop'
"Bundle 'Shougo/neocomplcache'
Bundle 'tpope/vim-surround'
Bundle 'Lokaltog/vim-easymotion'
"Bundle 'ervandew/supertab'
Bundle 'vim-scripts/tir_black'
Bundle 'othree/eregex.vim'
Bundle 'vim-scripts/Wombat'
Bundle 'vim-scripts/molokai'
Bundle 'vim-scripts/CCTree'
Bundle 'vim-scripts/taglist.vim'
Bundle 'majutsushi/tagbar'
Bundle 'kien/ctrlp.vim'
"sudo apt-get install vim-gnome
Bundle 'vim-scripts/fakeclip'
Bundle 'thinca/vim-logcat'
Bundle 'kshenoy/vim-signature'
Bundle 'vim-scripts/Quich-Filter'
Bundle 'bootleq/vim-tabline'
Bundle 'scrooloose/syntastic'
Bundle 'Raimondi/delimitMate'
Bundle 'terryma/vim-multiple-cursors'
" sudo pip install jedi
Bundle 'davidhalter/jedi-vim'
Bundle 'sudar/vim-arduino-syntax'
Bundle 'vim-scripts/sessionman.vim'
Bundle 'Yggdroot/LeaderF'
Bundle 'vim-scripts/Conque-GDB'
"Plugin 'Valloric/YouCompleteMe'
"Bundle 'Shougo/unite.vim'
"Bundle 'vim-scripts/DoxygenToolkit.vim'
"Bundle 'rking/ag.vim'
"Bundle 'mileszs/ack.vim'
"Bundle 'corntrace/bufexplorer'
"au filetype python Bundle 'vim-scripts/Pydiction'
"Bundle 'msanders/snipmate.vim'
"Bundle 'c9s/gsession.vim'
"Bundle 'kevinw/pyflakes-vim'
"Bundle 'vim-scripts/SuperTab'
"Bundle 'therealadam/vimfiles'
"Bundle 'vim-scripts/OmniCppComplete'
"sudo aptitude install clang libclang-dev
"Bundle 'Rip-Rip/clang_complete'
"Bundle 'Valloric/YouCompleteMe'
"Bundle 'sjl/gundo.vim'
"Bundle 'kingbin/vim-arduino'
filetype plugin indent on

"nmap <leader>U :GundoToggle<cr>
"let g:gundo_preview_bottom = 1
"let g:gundo_preview_height = 10
"let g:gundo_width = 30

cabbrev ack ack<c-\>esubstitute(getcmdline(), '^ack\>', 'Ack!', '')<cr>
if has ("Ack")
    copen 30
endif

" Basic Settings:
syntax on
filetype on
filetype plugin on
filetype indent on
colors tir_black
language messages zh_TW.utf-8

"set fencs=utf-8,gbk,big5,euc-jp,utf-16le
set fencs=utf-8,gbk,big5
set fenc=utf-8 enc=utf-8 tenc=utf-8
set t_ti= t_te=
set expandtab
set shiftwidth=4
set tabstop=4
set history=1000
set nomore
set laststatus=2
"set statusline=%<%f\ %h%m%r%=%-14.(%l,%c%V%)\ %P>
"set statusline=%4*%<\ %1*[%F]
"set statusline+=%4*\ %5*[%{&encoding}, " encoding
"set statusline+=%{&fileformat}%{\"\".((exists(\"+bomb\")\ &&\ &bomb)?\",BOM\":\"\").\"\"}]%m
"set statusline+=%4*%=\ %6*%y%4*\ %3*%l%4*,\ %3*%c%4*\ \<\ %2*%P%4*\ \>
set ruler
set softtabstop=4
set nobackup
"set cindent
set autoindent
set smartindent
set showcmd
set helplang=Cn
set hidden
set nofoldenable
set noswapfile
set number
"set mouse=nv
set hlsearch
set incsearch
set viminfo+=h
set nocp
set t_Co=256
set backspace=indent,eol,start whichwrap+=<,>,[,]
"autocmd FileType perl set keywordprg=perldoc\ -f
"copen 25

nmap <F8> :w<CR> :!astyle %<CR><CR> :edit!<CR>

"進行make的設置
"map <F8> :call Do_make()<CR>
"function Do_make()
"    set autochdir
"    set makeprg=make
"    execute "silent make"
"    execute "copen"
"endfunction

map <F9> :call Do_makei_clean()<CR>
function Do_makei_clean()
    set autochdir
    execute "silent make clean"
endfunction

"單檔gcc compile
nmap <C-c><C-c> :call Compile_gcc()<CR>
function Compile_gcc()
    if &filetype=="c"
        set autochdir
        execute "w"
        "execute "!clang -Wall -Wextra -O2 -g  % -o %:r -lm"
        execute "!gcc  -Wall  -pedantic -ansi -g -O0 % -o %:r -lm"
    elseif &filetype=="cpp"
        set autochdir
        execute "w"
        "execute "!clang++ -Wall -Wextra -O2 -g -std=c++11 % -o %:r"
        execute "!g++  -Wall  -pedantic -ansi -g -O0 % -o %:r -lm"
    elseif &filetype=="java"
        set autochdir
        execute "w"
        execute "!javac %:r.java"
    endif
endfunction

"單檔RUN
nmap <C-r><C-r> :call Run_gcc()<CR>
function Run_gcc()
    if &filetype=="c"
        set autochdir
        execute "! ./%:r"
    elseif &filetype=="cpp"
        set autochdir
        execute "! ./%:r"
    elseif  &filetype=="python"
        set autochdir
        execute "w !python"
    elseif  &filetype=="php"
        "sudo aptitude install php5-cli
        set autochdir
        execute "w !php"
    elseif  &filetype=="java"
        set autochdir
        execute "w !java %:r"
    endif
endfunction

imap <F1> <C-R>="[OOOOOOO]"<CR>
imap <F2> <C-R>=strftime("%F %T")<CR>
imap jj <ESC>
"imap ,, -><C-X><C-O>

" 刪除所有行未尾空格
nnoremap <F11> :%s/[ \t\r]\+$//g<cr>

nnoremap <leader>p  :NERDTreeToggle<CR>
nnoremap <leader>ff  :FufFile<CR>
nnoremap <leader>fb  :FufBuffer<CR>

"Remove the Windows ^M
noremap <leader>m  :%s/\r//g<CR>

"Remove the space
noremap <leader><space> :% s/\s\+$//g<CR>

"eregex.vim
let g:eregex_default_enable = 0
nnoremap ,/ :M/
nnoremap ,? :M?
"nnoremap ,/ /
"nnoremap ,? ?

nmap <tab> V>
nmap <s-tab> V<
vmap <tab> >gv
vmap <s-tab> <gv

"imap <C-h> <left>
"imap <C-j> <down>
"imap <C-k> <up>
"imap <C-l> <right>

"映射按鍵：剪切版、全選，系統有效
vmap <C-c> "+y
"vmap <C-x> "+x
"nmap <C-v> "+gP
"vmap <C-v> "+gP
nmap <C-a> ggVG

" ,p toggles paste mode
nnoremap ,p :set paste!<BAR>set paste?<CR>

" vim-logcat
nnoremap ,l :set filetype=logcat<CR>
nnoremap ,k :set filetype=<CR>

" :cd. change working directory to that of the current file
cmap cd. lcd %:p:h

function! SwitchSourceHeader()
  "update!
  if (expand ("%:e") == "cpp")
    find %:t:r.h
  else
    find %:t:r.cpp
  endif
endfunction

nmap ,s :call SwitchSourceHeader()<CR>

"nmap <F5> ^W_^W\|
"nmap <F6> ^W=
"imap <F5> <ESC>^W_^W\|a
"imap <F6> <ESC>^W=a
"nmap gF ^Wf

"setup doxygen：sudo apt-get install doxygen
map <F4>a  :DoxAuthor<CR>
map <F4>f  :Dox
map <F4>b  :DoxBlock<CR>
map <F4>l  :DoxLic<CR>
map <F4>c :odocClass<C-B>
map <F4>m :odocMember<C-B>

let g:DoxygenToolkit_authorName="Jason-Yao"
let s:licenseTag = "Copyright(C)\<enter>"
let s:licenseTag = s:licenseTag . "For free\<enter>"
let s:licenseTag = s:licenseTag . "All right reserved\<enter>"
let g:DoxygenToolkit_licenseTag = s:licenseTag
let g:DoxygenToolkit_briefTag_funcName="yes"
let g:doxygen_enhanced_color=1

let g:NeoComplCache_DisableAutoComplete = 1
"let g:SuperTabRetainCompletionType = 2
"let g:SuperTabDefaultCompletionType = "<C-X><C-U>"

noremap <C-W><C-U> :CtrlPMRU<CR>
nnoremap <C-W>u :CtrlPMRU<CR>

"let g:ctrlp_custom_ignore = '\.git$\|\.hg$\|\.svn$\|.rvm$'
let g:ctrlp_custom_ignore = {
    \ 'dir': '\v[\/]\.(git|hg|svn)$',
    \ 'file': '\v\.(exe|so|dll|bak|gds)$',
    \ 'link': 'SOME_BAD_SYMBOLIC_LINKS',
    \ }
let g:ctrlp_by_filename = 1 " only lookup file name
let g:ctrlp_cache_dir = '/tmp/ctrlp/cache/'
let g:ctrlp_working_path_mode=0
let g:ctrlp_match_window_bottom=1
let g:ctrlp_max_height=15
let g:ctrlp_match_window_reversed=0
let g:ctrlp_mruf_max=500
let g:ctrlp_follow_symlinks=1
let g:ctrlp_clear_cache_on_exit = 0
let g:ctrlp_max_files = 1000000
let g:ctrlp_user_command = 'find %s -type f | grep -P "\.h$|\.hpp$|\.c$|\.cc$|\.cpp$|\.java$"'
"let g:ctrlp_user_command = 'find %s -type f | grep -P "\.pl$|\.py$|\.lua$|\.xml$|\.sh$|\.mk$|\.h$|\.hh$|\.hpp$|\.c$|\.cc$|\.cpp$"'
" CtrlP - open in new tab by default
let g:ctrlp_prompt_mappings = {
    \ 'AcceptSelection("e")': ['<c-t>', '<2-LeftMouse>'],
    \ 'AcceptSelection("t")': ['<cr>'],
\ }


if has("gdb")
    set splitright
    set previewheight=60
    "set splitright
    "set splitbelow
    set asm=0
    set gdbprg=gdb
    nmap <silent><LEADER>g :run macros/gdb_mappings.vim<cr>
    nmap <silent> <LEADER>v :bel 8 split gdb-variables<CR>
    let g:vimgdb_debug_file = ""
    run macros/gdb_mappings.vim
endif

"hi Normal ctermfg=grey ctermbg=black
"hi Visual ctermfg=green ctermbg=black
"hi Search term=reverse cterm=standout ctermfg=green  ctermbg=yellow
"hi IncSearch term=reverse cterm=standout ctermfg=green ctermbg=yellow
"hi PmenuSel ctermbg=green ctermfg=Yellow

"Preserve last editing position in VIM
"need remove ~/.viminfo
if has("autocmd")
   autocmd BufRead *.txt set tw=78
   autocmd BufReadPost *
      \ if line("'\"") > 0 && line ("'\"") <= line("$") |
      \   exe "normal g'\"" |
      \ endif
endif

colorscheme molokai
set cursorline
set cursorcolumn
"highlight CursorLine cterm=none ctermbg=237
hi cursorcolumn cterm=bold ctermbg=237 ctermfg=none term=bold
hi cursorline cterm=bold ctermbg=237 ctermfg=none term=bold
highlight TabLineSel ctermfg=yellow ctermbg=darkblue cterm=bold
highlight StatusLine ctermfg=yellow ctermbg=darkblue cterm=bold
highlight LineNr ctermfg=yellow

" 刪除指標閃爍 , Terminator Profiles -> General 把 Cursor blink 勾選拿掉
set gcr=a:block-blinkon0

imap <C-F11> <C-R>=strftime("%x %X")<BAR><CR>. owen_wen@htc.com.<ESC> <C-R>
nnoremap <silent> <F3> :NERDTree<CR>

" Open .h if it's a cpp file, and vice versa.
function! OpenComplementFile()
  let f = expand('%')   " (1)
  let suffix = matchstr(f, '\.\a\+$')
  let pattern = suffix . "$"
  if suffix == '.h'
    let suffixes = ['.cpp', '.cc', '.mm', '.m', '.h']
    for suf in suffixes
      let target = substitute(f, pattern, suf, '')   " (2)
      if filereadable(target)
        break
      endif
    endfor
  elseif suffix == '.cpp' || suffix == '.cc' || suffix == '.m' || suffix == '.mm'
    let target = substitute(f, pattern, '.h', '')
    if !filereadable(target)
      let tmp = target
      let target = substitute(tmp, '\v(.+)\..+', 'public/\1.h', '')  " (3)
      if !filereadable(target)
        let target = substitute(tmp, '\v(.+)/(.+)\.(.+)', '\1/public/\2.h', '')
      endif
    endif
  else
    let target = ''
  endif

  if filereadable(target)
    exec 'vsplit ' target
  else
    echo "Complement file not found"
  endif
endfunction
nnoremap <silent> <F4> :call OpenComplementFile()<CR>


hi EasyMotionTarget ctermbg=none ctermfg=red
hi EasyMotionShade  ctermbg=none ctermfg=blue

"let g:agprg="<custom-ag-path-goes-here> --column"
"
"
au FileType qf call AdjustWindowHeight(3, 20)
function! AdjustWindowHeight(minheight, maxheight)
   let l = 1
   let n_lines = 0
   let w_width = winwidth(0)
   while l <= line('$')
       " number to float for division
       let l_len = strlen(getline(l)) + 0.0
       let line_width = l_len/w_width
       let n_lines += float2nr(ceil(line_width))
       let l += 1
   endw
   exe max([min([n_lines, a:maxheight]), a:minheight]) . "wincmd _"
endfunction

"將當前正在編輯但未保存的文件與已保存的做diff
func  DiffWithSaved ()
    let  ft = &filetype
     diffthis
    vnew  |  r  # |  normal!  1Gdd
     diffthis
    exe  "setlocal bt=nofile bh=wipe nobl noswf ro ft="  .  ft
endfunc
nnoremap <leader>df  :call DiffWithSaved()<CR>

"刪除行末空格
"func  DeleteTrailingWhiteSpace ()
"    normal  mZ
"     % s / \s\+$ // e
"    normal  `Z
"endfunc
"au  BufWrite  *  if  &ft  !=  'mkd'  |  call  DeleteTrailingWhiteSpace ()  |  endif

"Show_current_function_name_in_C_programs
"fun! ShowFuncName()
"  let lnum = line(".")
"  let col = col(".")
"  echohl ModeMsg
"
"
"  if &filetype=="java"
"      "java code
"      echo getline(search("\\h\\+\\s\\+\\h\\+\\s*(.*)", 'bW'))
"  else
"      " c/c++ code
"      echo getline(search("^[^ \t#/]\\{2}.*[^:]\s*$", 'bW'))
"  endif
"
"  echohl None
"  call search("\\%" . lnum . "l" . "\\%" . col . "c")
"endfun
"map F :call ShowFuncName() <CR>


" TagList options
" updatetime 加速
" set updatetime=1000
let Tlist_Close_On_Select = 1 "close taglist window once we selected something
let Tlist_Exit_OnlyWindow = 1 "if taglist window is the only window left, exit vim
let Tlist_Show_Menu = 1 "show Tags menu in gvim
let Tlist_Show_One_File = 1 "show tags of only one file
let Tlist_GainFocus_On_ToggleOpen = 1 "automatically switch to taglist window
let Tlist_Highlight_Tag_On_BufEnter = 1 "highlight current tag in taglist window
let Tlist_Process_File_Always = 1 "even without taglist window, create tags file, required for displaying tag in statusline
let Tlist_Use_Right_Window = 1 "display taglist window on the right
let Tlist_Display_Prototype = 1 "display full prototype instead of just function name
"set statusline=[%{&encoding}]\ [%n]\ %<%f\ %([%1*%M%*%R%Y]%)\ \ \ [%{Tlist_Get_Tagname_By_Line()}]\ %=%-19(\LINE\ [%l/%L]\ COL\ [%02c%03V]%)\ %P
set statusline=[%n]\ %<%f\ %([%1*%M%*%R%Y]%)\ \ \ [%{Tlist_Get_Tagname_By_Line()}]\ %=%-19(\LINE\ [%l/%L]\ COL\ [%02c%03V]%)\ %P\ [%{&encoding}]
"set statusline=[%n]\ %<%f\ %([%1*%M%*%R%Y]%)\ \ \ [%{Tlist_Get_Tag_Prototype_By_Line()}]\ %=%-19(\LINE\ [%l/%L]\ COL\ [%02c%03V]%)\ %P
"map F :TlistShowPrototype <CR>
map <F7> <ESC>:wincmd p<CR>
nmap <silent> <C-F12> :TagbarToggle<CR>
"自動更新
au! CursorHold *.[ch] nested exe "TlistUpdate"
au! CursorHold *.cpp nested exe "TlistUpdate"
au! CursorHold *.java nested exe "TlistUpdate"

" TagList options
"let Tlist_Close_On_Select = 1 "close taglist window once we selected something
"let Tlist_Exit_OnlyWindow = 1 "if taglist window is the only window left, exit vim
"let Tlist_Show_Menu = 1 "show Tags menu in gvim
"let Tlist_Show_One_File = 1 "show tags of only one file
"let Tlist_GainFocus_On_ToggleOpen = 1 "automatically switch to taglist window
"let Tlist_Highlight_Tag_On_BufEnter = 1 "highlight current tag in taglist window
"let Tlist_Process_File_Always = 1 "even without taglist window, create tags file, required for displaying tag in statusline
"let Tlist_Use_Right_Window = 1 "display taglist window on the right
"let Tlist_Display_Prototype = 1 "display full prototype instead of just function name
""let Tlist_Ctags_Cmd = /path/to/exuberant/ctags
"nnoremap <F5> :TlistToggle
"nnoremap <F6> :TlistShowPrototype
"set statusline=[%n]\ %<%f\ %([%1*%M%*%R%Y]%)\ \ \ [%{Tlist_Get_Tagname_By_Line()}]\ %=%-19(\LINE\ [%l/%L]\ COL\ [%02c%03V]%)\ %P

"vim-signature
nmap <C-j> ']
nmap <C-k> '[
"nmap .. ]`
"nmap ,, [`
nmap <C-.> ]`
nmap <C-,> [`


" Quich Filter {{{2
" 自動跟著原始檔案
"let g:filteringDefaultAutoFollow = 1

" After / search, use this to show the search result window
" just like quickfix list, but with sync scroll
nmap <space>l :call FilteringNew().addToParameter('alt', @/).run()<CR>
" After / search, use this to enter a keword filtering the search
" i.e. do a second search in the first search result
nmap <space>F :call FilteringNew().parseQuery(input('>'), '<Bar>').run()<CR>
" Re-open previous "look" windows selectively
nmap <space>g :call FilteringGetForSource().return()<CR>

" Old settings, name are more intuitive to understand
" nmap <Leader>F :call Gather(input("Filter on term: "), 0)<CR>
" nmap <Leader>l :call Gather(@/, 0)<CR>:echo<CR>
" nmap <Leader>g :call GotoOpenSearchBuffer()<CR>
" }}}

"Ag.vim
let g:agprg="ag --column"
cabbrev ag ag<c-\>esubstitute(getcmdline(), '^ag\>', 'Ag', '')<cr>
if has ("Ag")
    copen 30
endif

let g:ConqueGdb_Leader = '<Leader>'
let g:ConqueGdb_SrcSplit = 'right'
let g:ConqueGdb_GdbExe = 'gdb' "or arm-linux-gdb
"let g:ConqueGdb_GdbExe = 'arm-none-eabi-gdb' "or gdb

" 快速移動函數頭尾
nmap <leader>] ]}
nmap <leader>[ [{

"設定vim -p 檔案上限，不然會有限制的開啟前部分的檔案，後面就沒看到了。
set tabpagemax=1000

nmap tl :tabnext<cr>
nmap th :tabprev<cr>
nmap tn :tabnew<cr>
nmap td :tabclose<cr>


" 顯示空白
nmap <space>s :call ShowTrailingWhitespace()<CR>
function ShowTrailingWhitespace()
highlight WhitespaceEOL ctermbg=red guibg=red
match WhitespaceEOL /\s\+$/
endfunction
```

- 安裝vim 外掛套件

```
vim
: BundleInstall // 安裝
```
