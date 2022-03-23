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

"build, run, debug cpp files"
autocmd filetype cpp nnoremap <F9> :w <bar> !g++ -Wall -Wextra -pedantic --std=c++17 -O2 -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -Wno-variadic-macros % -o %:r -Wl,--stack,268435456<CR>
autocmd filetype cpp nnoremap <F10> :!./%:r<CR>
autocmd filetype cpp nnoremap <F12> :!gdb ./%:r <CR>

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
