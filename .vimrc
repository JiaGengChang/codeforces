set background=dark

:autocmd BufNewFile  *.cpp execute "0r ~/.vim/templates/".input("Template name: ").".cpp"
:autocmd TextChanged,TextChangedI <buffer> if &readonly == 0 && filereadable(bufname('%')) | silent write | endif

set tabstop=4
set softtabstop=4
set shiftwidth=4
set expandtab
set autoindent 
set smartindent 
set number
set mouse=a

autocmd filetype cpp nnoremap <F9> :w <bar> !g++ -std=c++17 % -o %:r -Wl,--stack,268435456<CR>
autocmd filetype cpp nnoremap <c-b> :w <bar> !g++ -std=c++17 % -o %:r -Wl,--stack,268435456<CR>
autocmd filetype cpp nnoremap <F10> :!./%:r<CR>
autocmd filetype cpp nnoremap <c-n> :!./%:r<CR>
autocmd filetype cpp nnoremap <F12> :!gdb ./%:r <CR>
autocmd filetype cpp nnoremap <c-m> :!gdb ./%:r <CR>

nnoremap <c-h> :wincmd h<CR>
nnoremap <c-l> :wincmd l<CR>
nnoremap <c-j> :wincmd j<CR>
nnoremap <c-k> :wincmd k<CR>

nnoremap <c-s> :w<CR>
inoremap <c-s> <Esc>:w<CR>a
vnoremap <c-s> <Esc>:w<CR> 

nnoremap <c-q> :wqa<CR>
inoremap <c-q> <Esc>:wqa<CR>
vnoremap <c-q> <Esc>:wqa<CR>

nnoremap <c-a> ggVG
vnoremap <c-x> "*y

inoremap { {}<Left>
inoremap {<CR> {<CR>}<Esc>O
inoremap {{ {
inoremap {} {}

autocmd filetype cpp nnoremap <c-c> :s/^\(\s*\)/\1\/\/<CR> :s/^\(\s*\)\/\/\/\//\1<CR> $
