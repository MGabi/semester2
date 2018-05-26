#!/bin/bash

#Sa se scrie un fisier de comenzi care are ca parametri triplete formate dintr-un nume de fisier, un cuvant si un numar k. Pentru fiecare astfel de triplet, se vor afisa toate liniile fisierului care contin cuvantul respectiv exact de k ori (shift, awk)

while [ $3 ]; do
	nume=$1
	cuv=$2
	nr=$3
	shift; shift; shift
	IFS=$'\n'
	for line in `cat $nume`; do
		count=0
		IFS=' '
		for word in $line; do
			if [ $word = $cuv ]; then
				(( count += 1 ))
			fi
		done
		if [ $count -eq $nr ]; then
			IFS='\n'
			echo $line
			IFS=' '
		fi
		IFS='\n'
	done
	IFS=$' '
done
