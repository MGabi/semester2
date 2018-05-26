#!/bin/bash

#1. CalculaČi numÄrul mediu de linii din fiČierele text dintr-un director dat ca parametru.
#(comenzi: find, file, wc).

nr=0
count=0

for f in $(find $1 -type f); do
	number=$(wc -l $f | awk '{print $1}')
	((nr += number))
	((count += 1))
done
echo $nr
echo $count
echo $((nr / count))
