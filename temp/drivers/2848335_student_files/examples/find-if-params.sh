#!/bin/bash
cd /sys/module
for i in *
do 
   if [ ! -d $i/parameters ]
   then      
         echo $i does NOT have parameters
   else
         echo $i DOES have parameters
   fi
done
