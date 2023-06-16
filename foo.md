## 1 & 2

`grep` before:

```
real    0m11,349s
user    0m0,649s
sys     0m1,654s
```

`free` before:

```
              total        used        free      shared  buff/cache   available
Mem:        6083924     1276180     2728072       64384     2079672     4457360
Swap:       1557568           0     1557568
```

`grep` after:

```
real    0m13,326s
user    0m0,677s
sys     0m1,880s
```

`free` after:

```
              total        used        free      shared  buff/cache   available
Mem:        6083924     1271880     3455224       64384     1356820     4480604
Swap:       1557568           0     1557568
```

## 5

`df` before:

```
Filesystem      Size  Used Avail Use% Mounted on
/root/ard        61M   14K   58M   1% /root/adir
```

`df` after:

```
Filesystem      Size  Used Avail Use% Mounted on
/root/ard       2,0M   14K  1,9M   1% /root/adir
```

## 6

```
root@ubuntu18:~/adir# cat /sys/kernel/debug/tracing/trace_pipe
 2)               |  brdx_make_request [brdx]() {
 2)               |    brdx_do_bvec [brdx]() {
 2)   1.947 us    |      brdx_lookup_page [brdx]();
 2)   6.232 us    |    }
 2) + 17.518 us   |  }
 2)               |  brdx_make_request [brdx]() {
 2)               |    brdx_do_bvec [brdx]() {
 2)   1.467 us    |      brdx_lookup_page [brdx]();
 2)   4.630 us    |    }
 2)   7.794 us    |  }
 ------------------------------------------
 2)   bash-6372    =>  kworker-8130
 ------------------------------------------

 2)               |  brdx_make_request [brdx]() {
 2)               |    brdx_do_bvec [brdx]() {
 2)   1.417 us    |      brdx_lookup_page [brdx]();
 2)   0.675 us    |      brdx_lookup_page [brdx]();
 2)   6.244 us    |    }
 2) + 14.796 us   |  }
 2)               |  brdx_make_request [brdx]() {
 2)               |    brdx_do_bvec [brdx]() {
 2)   0.649 us    |      brdx_lookup_page [brdx]();
 2)   0.644 us    |      brdx_lookup_page [brdx]();
 2)   3.311 us    |    }
 2)   9.096 us    |  }
 2)               |  brdx_make_request [brdx]() {
 2)               |    brdx_do_bvec [brdx]() {
 2)   0.784 us    |      brdx_lookup_page [brdx]();
 2)   0.695 us    |      brdx_lookup_page [brdx]();
 2)   4.343 us    |    }
 2)   6.116 us    |  }
 2)               |  brdx_make_request [brdx]() {
 2)               |    brdx_do_bvec [brdx]() {
 2)   0.620 us    |      brdx_lookup_page [brdx]();
 2)   0.614 us    |      brdx_lookup_page [brdx]();
 2)   3.380 us    |    }
 2)   5.854 us    |  }
 2)               |  brdx_make_request [brdx]() {
 2)               |    brdx_do_bvec [brdx]() {
 2)   1.375 us    |      brdx_lookup_page [brdx]();
 2)   0.613 us    |      brdx_lookup_page [brdx]();
 2)   4.748 us    |    }
 2)   6.527 us    |  }
 2)               |  brdx_make_request [brdx]() {
 2)               |    brdx_do_bvec [brdx]() {
 2)   0.613 us    |      brdx_lookup_page [brdx]();
 2)   0.612 us    |      brdx_lookup_page [brdx]();
 2)   3.365 us    |    }
 2)   5.753 us    |  }
 2)               |  brdx_make_request [brdx]() {
 2)               |    brdx_do_bvec [brdx]() {
 2)   0.741 us    |      brdx_lookup_page [brdx]();
 2)   0.608 us    |      brdx_lookup_page [brdx]();
 2)   4.044 us    |    }
 2)   6.343 us    |  }
 2)               |  brdx_make_request [brdx]() {
 2)               |    brdx_do_bvec [brdx]() {
 2)   0.840 us    |      brdx_lookup_page [brdx]();
 2)   7.154 us    |      brdx_insert_page.part.10 [brdx]();
 2)   0.661 us    |      brdx_lookup_page [brdx]();
 2) + 11.300 us   |    }
 2) + 15.156 us   |  }
 ```
