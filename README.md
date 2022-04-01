# Codeforces solution bank

A solution bank for division 2 problems on codeforces, and dotfiles for the text editor and terminal I use.

This repo is mainly to help sync my solutions across multiple machines.

## Horitonztal mode
Opened by entering `vs` from command line. Also showing NERDtree vim plugin.

<img src=doc/vim_tiling_2.png width="600">

## Vertical mode 
Suitable for viewing side by side with problem statement. Opened by entering `vv` from command line.

<img src=doc/vim_tiling.png width="600">

## Cygwin Setup (for windows users only)
Install cygwin (https://cygwin.com/install.html) and select the following packages to install:

```
gcc-core
gcc-g++
gdb
git
make 
vim
```

This is necessary for compiling and running c++ code. Other packages like ```tree``` and ```python39``` are recommended.

## Terminal setup

Append these commands from the dotfiles into yours. 

Alternatively, create a symbolic link of the provided dotfiles (```.bashrc, .minttyrc, .vimrc```) into your ```$HOME``` directory. 

```
ln -sr codeforces/.vimrc $HOME/.vim

ln -s codeforces/.vimrc $HOME/.vimrc

ln -s codeforces/.vimrc $HOME/.bashrc

ln -s codeforces/.vimrc $HOME/.minttyrc
```

Reopen terminal and commmands such as ```ebrc```, ```evrc``` to edit ```.bashrc``` and ```.vimrc``` should work.

## Vim setup

Despite the untradeable snappiness of terminal vim, the look that ships off with cygwin with are terrible. I followed others and used plugins to add some life to this.

Follow the instructions on https://github.com/junegunn/vim-plug to install the minimalist plugin manager.

This allows plugins listed inside my ```.vimrc``` to work, including plugins for the monokai theme, coloured status bar, and snippets.
