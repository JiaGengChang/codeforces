"General editor settings"
set tabstop=4
set softtabstop=4
set shiftwidth=4
set expandtab
set autoindent 
set smartindent 
set number
set ruler
set mouse=a

"Theme"
set t_Co=16
set background=dark
syntax enable

"build, run, debug cpp files"
"If you change the flags, you must precompile stdc++.h with the new flags
"for me it is located in 
"/usr/lib/gcc/x86_64-pc-cygwin/11/include/c++/x86_64-pc-cygwin/bits
autocmd filetype cpp nnoremap <c-1> :w <bar> !g++ -Wall -Wextra -pedantic --std=c++17 -O0 -Wno-variadic-macros % -o %:r <CR> <bar> :!./%:r<CR>;;;
autocmd filetype cpp nnoremap <c-3> :!./%:r<CR> ;
autocmd filetype cpp nnoremap <c-4> :!gdb ./%:r <CR>
autocmd filetype cpp nmap <F9>  <c-1>
autocmd filetype cpp nmap <F10> <c-3>
autocmd filetype cpp nmap <F12> <c-4>

"window nav"
nnoremap <c-h> :wincmd h<CR>
nnoremap <c-l> :wincmd l<CR>
nnoremap <c-j> :wincmd j<CR>
nnoremap <c-k> :wincmd k<CR>

"write to buffer"
nnoremap <c-w> :w<CR>
inoremap <c-w> <Esc>:w<CR>a
vnoremap <c-w> <Esc>:w<CR> 

"write and close all windows"
nnoremap <c-q> :wqa<CR>
inoremap <c-q> <Esc>:wqa<CR>
vnoremap <c-q> <Esc>:wqa<CR>

"Select all, yank all"
nnoremap <c-a> ggVG
vnoremap <c-x> "*y

"Brackets autocompletion"
inoremap { {}<Left>
inoremap {<CR> {<CR>}<Esc>O
inoremap {{ {
inoremap {} {}

"comment/uncomment lines"
autocmd filetype cpp nnoremap <c-c> :s/^\(\s*\)/\1\/\/<CR> :s/^\(\s*\)\/\/\/\//\1<CR> $

"open cpp template"
:autocmd BufNewFile  *.cpp execute "0r ~/.vim/templates/".input("Template name: ").".cpp"

"File viewer
nnoremap <F5> :NERDTree<CR>

"vim-plug stuff below"
call plug#begin()
Plug 'tpope/vim-sensible'
Plug 'MarcWeber/vim-addon-mw-utils'
Plug 'tomtom/tlib_vim'
Plug 'garbas/vim-snipmate'
Plug 'honza/vim-snippets'
Plug 'preservim/nerdcommenter'
Plug 'itchyny/lightline.vim'
Plug 'sickill/vim-monokai'

" On-demand loading
Plug 'scrooloose/nerdtree', { 'on': 'NERDTreeToggle' }
call plug#end()

colorscheme monokai

let g:snipMate = { 'snippet_version' : 1 }


" Start NERDTree when Vim is started without file arguments.
" autocmd StdinReadPre * let s:std_in=1
" autocmd VimEnter * if argc() == 0 && !exists('s:std_in') | NERDTree | endif
" Start NERDTree when Vim starts with a directory argument.
" autocmd StdinReadPre * let s:std_in=1
" autocmd VimEnter * if argc() == 1 && isdirectory(argv()[0]) && !exists('s:std_in') | execute 'NERDTree' argv()[0] | wincmd p | enew | execute 'cd '.argv()[0] | endif
