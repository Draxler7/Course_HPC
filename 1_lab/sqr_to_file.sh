#!/bin/bash
echo n,S,T
for ((i=0; i<10; i++)); do
	./$1 1000
done
echo ""

echo n,S,T
for ((i=0; i<10; i++)); do
	./$1 10000
done
echo ""

echo n,S,T
for ((i=0; i<10; i++)); do
	./$1 100000
done
echo ""

echo n,S,T
for ((i=0; i<10; i++)); do
	./$1 1000000
done
echo ""

echo n,S,T
for ((i=0; i<10; i++)); do
	./$1 10000000
done
echo ""

echo n,S,T
for ((i=0; i<10; i++)); do
	./$1 50000000
done
echo ""

echo n,S,T
for ((i=0; i<10; i++)); do
	./$1 100000000
done
echo ""

echo n,S,T
for ((i=0; i<10; i++)); do
	./$1 300000000
done
echo ""