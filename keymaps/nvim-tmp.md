# Nvim

* setting `path` when `gf`-ing
* `[I` ,`[<Tab>`

## Vim-markdown

* `zm`: increases fold level throughout the buffer
* `zc`: close a fold your cursor is on
* `zC`: close a fold your cursor is on recursively

* `zR`: opens all folds
* `zM`: folds everything all the way

* `za`: open a fold your cursor is on
* `zA`: open a fold your cursor is on recursively
* `zr`: reduces fold level throughout the buffer

## Tabs + splits

## Telescope

* `,ff` - find file
* `,lg`/`,sg` - live/static grep
* `,gf` - git files

## LSP

* `<CR>` - confirm
* `<c-Space>` - trigger autocomplete
* `,rr` - rename

* `[d`/`]d`- browse diagnostics
* `K` - hover
* `,ca` - code action
* `,od` - open diagnostic
* `,rr` - list references
* `,ws` - list symbols
* `,sh` - signature help

## Misc

* `{`/`}` - skip text by paragraphs fovkojfw
* `K` - browse man
* `=ap` - autoindent
* `vip` - select inside paragraph
* `gv` reselect previous selection
* `:32`
* `,nw`/`,nW` - search forward word/WORD
* `,ex`
* `g$` - rerurn command on whole file
* `:x` - `:wq`

## TODO topics

* splitting, tabs + harpoon
* debugging
* treesitter
* lsp
* lualine

## Buffers and file manipulation

* `:e foo.txt`
* `:buffers`, `:b1`
* `:find`
* `:tabfind`
* `:e .`
* `:edit .`, `%` - create new fil

## Rare

* `gu`/`gU` - Uncapitalize and capitalize words/lines.
* `g~{motion}` - capitalize
* `c-f`/`c-b` page forward/backwards
* `25%`
* `:earlier 2m`
* `<ctrl+u>`(insert mode) - delete characters from start of line till cursor

### Registers

* `"+` - clipboard register
* `"*` - primary register
* `V"by` - copy line to register b
* `"0p` - paste from non-volatile yank register
