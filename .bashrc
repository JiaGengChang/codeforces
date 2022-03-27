# common linux commands
alias l='ls -lrth --color'
alias la='ls -lrtha --color'
alias ebrc='vi ~/.bashrc'
alias evrc='vi ~/.vimrc'
alias ebpf='vi ~/.bash_profile'
alias etmp='vi ~/.vim/templates/sol.cpp'
alias esnp='vi ~/.vim/snippets/cpp.snippets'
alias ..='cd ..'
alias ...='cd ../..'
alias ....='cd ../../..'
alias .....='cd ../../../..'
alias refresh='source ~/.bashrc'
alias c="clear"
alias qq="logout"

# create directory and cd into it
mcd() { mkdir -p "$@" && cd "$@"; }

# open the following files:
# 1 solution file
# 2 stderr file
# 3 stdin file
# 4 stdout file

# vv = vertical screen mode
alias vv='vi -c "e error.txt|split sol.cpp|below split input.txt|rightb vsplit output.txt|1 res +20|2 res +10"'

# vs = horizontal screen mode
alias vs='vi -c "e sol.cpp|vsplit input.txt|split output.txt|split error.txt"'

# open all files needed for stress testing solution
# horizontal screen mode
alias va='vi -c "e random.cpp|e brute.cpp|e sol.cpp|vsplit input.txt|split output.txt|split error.txt"'

# create directory and basic files for writing solution

# version 1: hasty version
mcp() { 
  mkdir -p "$@" && 
  cp ~/.vim/templates/sol.cpp "$@"/sol.cpp && 
  touch "$@"/output.txt "$@"/input.txt "$@"/error.txt &&
  cd "$@";
}

# version 2: stress testing version
mfull() {
  mkdir -p "$@" && 
  cp ~/.vim/templates/sol.cpp "$@"/sol.cpp && 
  cp ~/.vim/templates/sol.cpp "$@"/brute.cpp && 
  cp ~/codeforces/random.cpp "$@"/random.cpp && 
  cp ~/codeforces/checker.sh "$@"/checker.sh && 
  touch "$@"/output.txt "$@"/input.txt "$@"/error.txt &&
  cd "$@";
}












