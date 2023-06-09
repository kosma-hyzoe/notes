# Vim

## Misc/Temp

* **:32** - go to line 32
* alt+movement - back to normal mode
* **ctrl + g** - display position info
* **5gg** (or **5G**) - move to the beginning of line 5
* **$G**(or just **G**) - go to the last line
* **ctrl + f/b** page forward/backward
* 0/^ - move to the beginning of line
* **x/X** - delete the next/previous character
* **2d3w** - delete the 3w motion 

## Useful combinations

* ci) - change inside curly brackets (also di} for delete etc.)
* daw - "delete a word and what's around it(whitespaces)"
* diw - "delete a word from inside"

## Navigation

* ge - like b but at the "back end" of a word
* gj/gk - scroll a line spanning multiple editor lines
* gd - move to declaration
* gf - move to a highlighted file name
* gv - go back to selected text
* 25%
* 10gg / 10 G - go to line 10
* ^ - move to first non-blank character of the line
* ctrl d/u - scroll half a page
* {/} - skip text by paragraphs
* '' - go back to last location

## Editing

* d0 - delete to beginning of line

## Formatting 

* gq - split wrapped lines
* gU/gu - capitalize/uncapitalize <motion>
* ~ - capitalize/uncapitalize char
* J - join lines
* gJ - join with no spaces

## Commands

* % - apply to whole file
* g& - run the previously run command on the whole file(i.e. substitution)
* earlier 10m - "go back in time", 10 minutes

## Selecting, yanking, pasting, deleting

* ctrl+v - block selection
* yy - yank line
* "+ - clipboard register
* "* - primary register
* V"by - copy line to register b
* "0p - paste from non-volatile yank register 
* ctrl+u - delete characters from start of line till cursor (insert mode)

## Misc

* ZQ - force quit
* ZZ - quit
* :x - :wq equivalent

* U - undo all changes
* ctrl+g - display position info
* alt+normal mode command - enter normal mode 
