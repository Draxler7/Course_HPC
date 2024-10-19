#!/bin/bash

echo S,Ns,dT,Error
for ((i=0; i<5; i++)); do
	./$1
done
