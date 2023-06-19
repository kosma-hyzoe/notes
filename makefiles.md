# Makefiles

Code by [Gabe Palmer](https://github.com/gwu-cs-os/evening_os_hour).

## Misc

* automate compilation and linking
* recompile only what needs recompiling
* easier to maintain

* good to add `SHELL = /bin/sh` at the beginning?

## Simple Makefile

```make
CC=gcc
INCDIRS=-I.
OPT=-O0
CFLAGS=-Wall -Wextra -g $(INCDIRS) $(OPT)

CFILES=x.c y.c
OBJECTS=x.o y.o

BINARY=run

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

# regular expression where % is a wildcard
# this version is NOT smart enough to recompile .h files only
%.o:%.c # building objects need .c files
	$(CC) $(CFLAGS) -c -o $@ $^ # $@ - target,  $^ - deps

clean:
	rm -rf $(BINARY) $(OBJECTS)
```

## Advanced Makefile

```make
BINARY=bin
CODEDIRS=. lib
INCDIRS=. ./include/ # can be list

CC=gcc
OPT=-O0
# generate files that encode make rules for the .h dependencies
DEPFLAGS=-MP -MD
# automatically add the -I onto each include directory
CFLAGS=-Wall -Wextra -g $(foreach D,$(INCDIRS),-I$(D)) $(OPT) $(DEPFLAGS)

# for-style iteration (foreach) and regular expression completions (wildcard)
CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
# regular expression replacement, 'change .c to .o from $CFILES'
OBJECTS=$(patsubst %.c,%.o,$(CFILES))
DEPFILES=$(patsubst %.c,%.d,$(CFILES))

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

# only want the .c file dependency here, thus $< instead of $^.
#
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES)

# shell commands are a set of keystrokes away
distribute: clean
	tar zcvf dist.tgz *

# @ silences the printing of the command
# $(info ...) prints output
diff:
	$(info The status of the repository, and the volume of per-file changes:)
	@git status
	@git diff --stat

# include the dependencies
-include $(DEPFILES)

# add .PHONY so that the non-targetfile - rules work even if a file with the same name exists.
.PHONY: all clean distribute diff
```
