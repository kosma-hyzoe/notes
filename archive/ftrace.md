# Ftrace and kernel debugging

## Ftrace

* frond-ends: `ftrace-cmd`, `perftools`, `perf trace`(?)
* `/sys/kernel/tracing` or `/sys/kernel/debug/tracing` on kernels < 4.1
* check availablity with `cat /proc/filesystems | grep tracefs` (should output
  nodev tracefs)
* check if mounted with `mount | grep tracefs`, mount with `mount -t tracefs nodev /sys/   kernel/tracing`.
* `cat available_tracers`
* `cat trace` - get the output

```sh
cat set ftrace_pid
echo pid > set_ftrace_pid

# "vim-like" options
echo branch > trace_options
echo nobranch > trace_options
```

## Important tracers

```txt
"nop"

	This is the "trace nothing" tracer. To remove all
	tracers from tracing simply echo "nop" into
	current_tracer.
 "function"

	Function call tracer to trace all kernel functions.

  "function_graph"

	Similar to the function tracer except that the
	function tracer probes the functions on their entry
	whereas the function graph tracer traces on both entry
	and exit of the functions. It then provides the ability
	to draw a graph of function calls similar to C code
	source.

  "blk"

	The block tracer. The tracer used by the blktrace user
	application.

  "hwlat"

	The Hardware Latency tracer is used to detect if the hardware
	produces any latency. See "Hardware Latency Detector" section
	below.

  "irqsoff"

	Traces the areas that disable interrupts and saves
	the trace with the longest max latency.
	See tracing_max_latency. When a new max is recorded,
	it replaces the old trace. It is best to view this
	trace with the latency-format option enabled, which
	happens automatically when the tracer is selected.

"preemptoff"

        Similar to irqsoff but traces and records the amount of time
        for which preemption is disabled.

 "preemptirqsoff"

	Similar to irqsoff and preemptoff, but traces and
	records the largest time for which irqs and/or preemption
	is disabled.

  "wakeup"

	Traces and records the max latency that it takes for
	the highest priority task to get scheduled after
	it has been woken up.
        Traces all tasks as an average developer would expect.

  "wakeup_rt"

        Traces and records the max latency that it takes for just
        RT tasks (as the current "wakeup" does). This is useful
        for those interested in wake up timings of RT tasks.

  "wakeup_dl"

	Traces and records the max latency that it takes for
	a SCHED_DEADLINE task to be woken (as the "wakeup" and
	"wakeup_rt" does).

  "mmiotrace"

	A special tracer that is used to trace binary module.
	It will trace all the calls that a module makes to the
	hardware. Everything it writes and reads from the I/O
	as well.

  "branch"

	This tracer can be configured when tracing likely/unlikely
	calls within the kernel. It will trace when a likely and
	unlikely branch is hit and if it was correct in its prediction
	of being correct.
```

## Tracepoints

* no overhead if noone activates them
* `dtrace` for userspace, `ftrace` for kernel?

## Other tools

* `addr2line` cant translate memory address to line of src code
* `faddr2line` will do the same with stack dump function offset TODO
* `pstore` for persistent data storage
* `kdump` runs dump-capture kernel

## strace

* `strace -p $PID`
* `strace -c -p $PID` - generate report of totat time, calls and errros
* `strace -f -p $PID` - trace children/forks
* `strace -i $COMMAND` - print instruction pointer
* `strace -t` - show time of date
* `strace -o OUTPUT` - redirect to file
* `strace -T` - print command time spent in system calls
* `strace -d` - show debugging output

* `sudo strace -e trace=$SYS_FUNCS_CALL $LINUX_COMMAND` - trace specific
  sys calls only (can specify multiple, i.e. `trace=write,read`)
* `strace -q -e trace=process` - trace based on condition (in this case
  process management)
  `strace -q -e trace=file` - tracing involving files
  `strace -q -e trace=memory` - tracing memory mapping
