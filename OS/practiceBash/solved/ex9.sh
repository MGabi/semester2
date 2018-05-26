#!/bin/bash

#8. Sa se scrie un fisier de comenzi care va afisa toate numele de fisiere dintr-un director dat ca parametru si din subdirectoarele sale, care au numele mai scurte de 8 caractere.
#Pentru acestea, daca sunt fisiere text, li se vor afisa primele 10 linii.


FILE=$1
for F in $(find $FILE  -type f); do
	NAME=$(echo "$F" | grep -o '[^/]*$')
	echo $NAME
	if [ ${#NAME} -lt 8 ]; then
		DATA=$(file $F)
		if echo $DATA | grep -q "ASCII text"; then
			printf "%s\n" $(head -n+10 $F)
		fi
	fi
done
