#!/bin/bash

echo "1 Core"
echo n,S,T
for ((i=0; i<5; i++)); do
	taskset -c 0 ./$1 $2
done

echo "2 Cores"
echo n,S,T
for ((i=0; i<5; i++)); do
	taskset -c 0-1 ./$1 $2
done

echo "3 Cores"
echo n,S,T
for ((i=0; i<5; i++)); do
	taskset -c 0-2 ./$1 $2
done

echo "4 Cores"
echo n,S,T
for ((i=0; i<5; i++)); do
	taskset -c 0-3 ./$1 $2
done

echo "5 Cores"
echo n,S,T
for ((i=0; i<5; i++)); do
	taskset -c 0-4 ./$1 $2
done

echo "6 Cores"
echo n,S,T
for ((i=0; i<5; i++)); do
	taskset -c 0-5 ./$1 $2
done

echo "7 Cores"
echo n,S,T
for ((i=0; i<5; i++)); do
	taskset -c 0-6 ./$1 $2
done

echo "8 Cores"
echo n,S,T
for ((i=0; i<5; i++)); do
	taskset -c 0-7 ./$1 $2
done