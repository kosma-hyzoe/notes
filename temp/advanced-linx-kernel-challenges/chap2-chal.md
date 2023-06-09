# Advanced Linux: The Linux Kernel Chapter 2 Challenges

3. Yes. (`ls -l $(which init)`).
    * Yes. (`ps -ef | grep init`)
5. All processes are descendants of `init`/`systemd`. In my case, `pstree` has
   a parent tree `systemd` -> `tmux: server` -> `zsh` -> `pstree`

Let me know if you'd like me to reproduce challenges 1, 2 and 4 on my VM :)
