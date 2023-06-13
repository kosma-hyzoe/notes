#!/bin/bash
cd /sys/module
for i in *
do 
   if [ -d $i/parameters ]
   then
      find $i/parameters -type f -exec grep \" {} \;
   fi
done
