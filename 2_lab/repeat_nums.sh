#!/bin/bash

echo  "N, S, T_OMP, T_TIMESPEC"

for ((j=4; j<12; j++)); do
	let "c = 10 ** j"
  	for ((i=0; i<5; i++)); do
    		./$1 $c
  	done
	echo ""
done
