#!/bin/sh

// Компилирование и запуск этой же программы

if gcc $1 -o $2 ; then
	echo "Succesfull"
	./$2
else
	echo "Failed"
fi
