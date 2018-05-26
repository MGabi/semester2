#!/bin/bash

#R1
#Scrieti un script shell care primeste ca parametrii in linia de comanda o cale catre un director sursa si una catre o destinatie

#copiaza tot din sursa in destinatie adaugand la numele fisierului numele .bkup
echo $1
echo $2
for FILE in `find * $1 -type f`; do
	name=`echo $FILE | awk -F'\/' '{print $1}'`
	mv $FILE $2 --backup
done
