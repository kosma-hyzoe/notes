# Foo

* "wake_up() / wake_up_interruptible() wakes up all non-exclusive tasks and only
one exclusive task"
* wake_up_all() / wake_up_interruptible_all() wakes up all non-exclusive and all
exclusive tasks

* `void wait_event(queue, condition);`
    * Sleeps until the task is woken up and the given C expression is true.
* `int wait_event_killable(queue, condition);`
    * Can be interrupted, but only by a fatal signal (SIGKILL). Returns -ERESTARTSYS if
      interrupted.
* `int wait_event_interruptible(queue, condition);`
    * Can be interrupted by any signal. Returns -ERESTARTSYS if interrupted.
* int wait_event_timeout(queue, condition, timeout);
    * Also stops sleeping when the task is woken up or the timeout expired (a timer is
      used).
    * Returns 0 if the timeout elapsed, non-zero if the condition was met.
* int wait_event_interruptible_timeout(queue, condition, timeout);
    * Same as above, interruptible.
    * Returns 0 if the timeout elapsed, -ERESTARTSYS if interrupted, positive value if the
      condition was met.
* `wait_for_completion()` - no condition, adds add the end(?) of wait queue
* cat /sys/kernel/debug/irq/irqs/
