# Pacman Cheatsheet

Based on [Luke Smith's guide](https://www.youtube.com/watch?v=-dEuXTMzRKs).

## -S

* -S *program-name* - install ("sync") the program(s).
* -Ss *program-name* - search the program(s).
* -Sy - check for available updates .
* -Su - install the available updates,  Usually used in combination (`-Syu`).
* -Syy - double-check for available updates.
* -Syuw - choose what to update manually.

## -R

* -R *program-name* - remove the program(s).
* -Rs *program-name* remove with dependencies.
* -Rn *program-name* remove with .configs (usually used in combination: `-Rns`).

## -Q

* -Q - list all programs.
* -Qe - list user-installed programs.
* -Qu - list program names only (no version info).
* -Qn - main repository only.
* -Qm - AUR only.
* -Qdt - list unneeded dependencies.

## See also:

* https://wiki.archlinux.org/title/Pacman/Rosetta
