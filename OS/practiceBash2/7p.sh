#!/bin/bash

#Sa se afiseze pentru fiecare fisier din linia de comanda linia care apare de cele mai multe ori, afisarea facandu-se in ordinea decsrescatoare a numarului de aparitii (sort, uniq, head).

while [ $1 ]; do
	cat $1 | sort | uniq -c | cut -c9-
	shift
done
