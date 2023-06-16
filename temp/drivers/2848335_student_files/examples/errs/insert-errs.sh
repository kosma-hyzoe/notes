#!/bin/bash
for i in $(seq -10 -1)
do 
   echo -n "$i: " 
   sudo insmod errs.ko errval=$i 2>&1
done
