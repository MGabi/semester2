#!/bin/bash

#Afișați primele 5 linii și ultimele 5 linii din fișierele de tip text din directorul curent; dacă un fișier are mai puțin de 10 linii, afișați fișierul complet (comenzi: head, tail, find, file, wc).kedc

for F in `find * /usr/bin/ -type f`; do
	if file $F | grep 'ASCII'; then
		lines=`wc -l $F`
		echo '#############' $lines
		if [ $lines -gt 10 ]; then
			head -n 5 $F
			tail -n 5 $F
		else
			cat $F
		fi
	fi
done
