#!/bin/bash

read -p "Введите количество повторений: " n

if [[ $n -gt 0 ]] && [[ $n =~ ^[0-9]+$ ]]; then
	declare -i i
  	for ((i=0; i<$n; i++)); do
    		./$1
  	done
else
  echo "Неверный вод числа!"
fi
