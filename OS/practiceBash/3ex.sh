#!/bin/bash

#3. AfiČaČi primele 5 linii Či ultimele 5 linii din fiČierele de tip text din directorul curent.
#DacÄ un fiČier are mai puČin de 10 linii, afiČaČi fiČierul complet (comenzi: head, tail, find, file, wc).

for f in `find $1 -type f`; do
	if file $f | grep -q "ASCII"; then
		lines=$(wc -l $f | awk '{print $1}')
		echo '##########'
		echo $f
		if [ $lines -lt 10 ]; then
			echo $(cat $f)
		else
			echo 'head'
			cat $f | head -n 5
			echo 'tail'
			cat $f | tail -n 5
		fi
		echo ' '
	fi
done
