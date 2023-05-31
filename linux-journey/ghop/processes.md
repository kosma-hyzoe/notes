# Processes

## todo

* zombie processes

## `ps`

* `a` all, including other users
* `u` - more details
* `x` - include non-TTY
* `l` - long format
* USER means effective user
* STAT status code
* shell terminals are pseudoterminals, PTS
* all processes(?) are forked children of process 1

## Termination

* parent waits with `wait()`
* children become orphans taken care of by init when a parent dies before them

## Signals

* TODO block vs ignore?
* HUP: 1 (hangup)
* INT: 2 (interrupt)
* KILL: 9 - no clean up
* SEGV: 11
* TERM: 15 - with clean up

## niceness

* high nice value - low CPU priority
* `nice -n 5 apt upgrade`
* `renice 10 -p $(pidof top)`

## States

* R: running or runnable, it is just waiting for the CPU to process it
* S: Interruptible sleep, waiting for an event to complete, such as input from
the terminal
* D: Uninterruptible sleep, processes that cannot be killed or interrupted with
a signal, usually to make them go away you have to reboot or fix the issue
* Z: Zombie, we discussed in a previous lesson that zombies are terminated
processes that are waiting to have their statuses collected
* T: Stopped, a process that has been suspended/stopped

## Job Control

* fg with no flags will foreground the first job
* you can kill background jobs with `kill %1`

```bash
cat  &
# [1] 414860
jobs -l
# [1]  + 414860 running    ./long_running.sh > /tmp/out
disown %1
jobs -l
#
```
