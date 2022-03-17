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
let g:solarized_termcolors=256
set background=light
colorscheme desert

"build, run, debug"
autocmd filetype cpp nnoremap <F9> :w <bar> !g++ -std=c++17 % -o %:r -Wl,--stack,268435456<CR>
autocmd filetype cpp nnoremap <c-b> :w <bar> !g++ -std=c++17 % -o %:r -Wl,--stack,268435456<CR>
autocmd filetype cpp nnoremap <F10> :!./%:r<CR>
autocmd filetype cpp nnoremap <c-n> :!./%:r<CR>
autocmd filetype cpp nnoremap <F12> :!gdb ./%:r <CR>
autocmd filetype cpp nnoremap <c-m> :!gdb ./%:r <CR>

"window nav"
nnoremap <c-h> :wincmd h<CR>
nnoremap <c-l> :wincmd l<CR>
nnoremap <c-j> :wincmd j<CR>
nnoremap <c-k> :wincmd k<CR>

"ergonomic write buffer"
nnoremap <c-s> :w<CR>
inoremap <c-s> <Esc>:w<CR>a
vnoremap <c-s> <Esc>:w<CR> 

"quit all windows"
nnoremap <c-q> :wqa<CR>
inoremap <c-q> <Esc>:wqa<CR>
vnoremap <c-q> <Esc>:wqa<CR>

"Select and yank all"
nnoremap <c-a> ggVG
vnoremap <c-x> "*y

"Autocompletion"
inoremap { {}<Left>
inoremap {<CR> {<CR>}<Esc>O
inoremap {{ {
inoremap {} {}

"comment/uncomment lines"
autocmd filetype cpp nnoremap <c-c> :s/^\(\s*\)/\1\/\/<CR> :s/^\(\s*\)\/\/\/\//\1<CR> $

"open cpp template"
:autocmd BufNewFile  *.cpp execute "0r ~/.vim/templates/".input("Template name: ").".cpp"
