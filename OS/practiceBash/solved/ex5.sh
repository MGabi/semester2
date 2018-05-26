#!/bin/bash

#5. Pentru fiecare parametru din linia de comandÄ: dacÄ e fiČier, se vor afiČa numele, numÄrul de caractere
#Či de linii din el (ĂŽn aceastÄ ordine), iar dacÄ e director, numele Či cĂ˘te fiČiere conČine (inclusiv ĂŽn subdirectoare).
#(comenzi: test, wc, awk, find).

touch temporary

for param in $*; do
	if [ -f $param ]; then	
		echo $param > temporary
	    echo $(awk -F/ '{print $NF}' temporary)
   	    echo $(wc -c $param | grep -o "[0-9]* ")
        echo $(wc -l $param | grep -o "[0-9]* ")	
	elif [ -d $param ]; then
		echo $param > temporary
		echo $(awk -F/ '{print $NF}' temporary)
		NR=0
		for F in $(find $param -type f); do
			NR=$(($NR+1))
		done
		echo "Directorul contine $NR fisiere"
	else
		echo "Parametrii sunt incorecti"
		exit 1
	fi
done

rm temporary
