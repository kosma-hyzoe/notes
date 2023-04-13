" Comfy ctrl+c/ctrl+v
vnoremap <C-c> "+y
map <C-v> "+p
" Vanilla cursor shapes
let &t_SI = "\e[6 q"
let &t_EI = "\e[2 q"
" For faster hjkl-ing around and stuff 
set ttimeoutlen=50
" Enable the use of the backspace key
set backspace=indent,eol,start
" Be a grown-ass adult, use the mouse if you need to
set mouse=a


" Have the prompt 5 lines above the file ends when scrolling 
set scrolloff=5 
" Sane encoding
set encoding=utf-8 
" For speed
set noswapfile
" split tabs at the bottom and on the right
set splitbelow splitright 
" ctrl+n autocompletion
set wildmode=longest,list,full 
set number relativenumber " Enable line numbers and relative numbers
set wrap " Enable line wrapping
set linebreak " No wrapping around 'words'

" Highlight search results
set hlsearch
" Enable incremental searching
set incsearch
" Enable smart case searching
set smartcase

" Enable the use of the leader key
let mapleader = ","

" Plugins
call plug#begin('~/.vim/plugged')
Plug 'tpope/vim-surround'
Plug 'vimwiki/vimwiki'
Plug 'preservim/nerdtree'
Plug 'machakann/vim-highlightedyank'
call plug#end()
