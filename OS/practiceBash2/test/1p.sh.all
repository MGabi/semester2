#!/bin/bash

#Calculați numărul mediu de linii din fișierele text dintr-un director dat ca parametru (comenzi: find, file, wc).
lines=0
count=0
for F in `find * $1 -type f`; do
	((lines += `cat $F | wc -l`))
	((count += 1))
done
echo 'Nr mediu de linii :' $((lines/count))
