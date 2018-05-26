#!/bin/bash

#2. AfiČaČi numele fiČierelor dintr-un director dat ca parametru care conČin numere de peste 5 cifre.

for f in `find $1 -type f`; do
	if file $f | grep -q 'ASCII'; then
		if cat $f | grep -q '[0-9]'; then
			nume=$(echo $f | awk -F':' '{print $1}' | awk -F'/' '{print $NF}')
			echo $nume
		fi	
	fi
done
