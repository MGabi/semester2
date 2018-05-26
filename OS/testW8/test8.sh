#!/bin/bash

#R1
#Scrieti un script shell care primeste ca parametrii in linia de comanda o cale catre un director sursa si una catre o destinatie

#copiaza tot din sursa in destinatie adaugand la numele fisierului numele .bkup

if [ -d $1 ]; then
	if ! [ -d $2 ]; then
		mkdir $2
	fi

	for FILE in `find $1 -type f`; do
		name=`echo $FILE | awk -F'/' '{print $NF}'`
		cp $FILE $2
		mv $2/$name $2/$name'.bkup'
	done
else
	echo 'Directorul sursa nu exista!'
fi
