#!/bin/bash
cd /sys/module
for i in *
do 
   if [ -d $i/parameters ]
   then
      find $i/parameters -type f -perm /222 -exec ls -l {} \;
   fi
done
