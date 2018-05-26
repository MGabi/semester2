#!/bin/bash

#7. Sa se afiseze pentru fiecare fisier din linia de comanda linia care apare de cele mai multe ori,
#afisarea facandu-se in ordinea decsrescatoare a numarului de aparitii. (comenzi: sort, uniq, head).

for F in $*; do
	if [ -f $F ]; then
		cat $F | sort | uniq -c | sort -n -r | sed 's/^ *[0-9]//g' 
	fi
done
