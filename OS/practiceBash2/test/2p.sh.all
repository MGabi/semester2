#!/bin/bash

#Afișați numele fișierelor dintr-un director dat ca parametru care conțin numere de peste 5 cifre.

for F in `find * $1 -type f`; do
	if grep '[0-9]\{6,\}' $F; then
		echo $F
	fi
done
