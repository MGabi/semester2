#!/bin/bash

#9. Sa se scrie un program shell care pentru fiecare fisier cu drepturile 755 dintr-un director (si subdirectoarele sale) dat ca parametru ii schimba drepturile de acces in 744.
#Inainte de a schimba drepturile de acces, pogramul cere confirmare din partea utilizatorului (pentru fiecare fisier in parte).
(comenzi: find, chmod, read)

for F in $(find $1 -type f); do
	PERM=$(stat -c "%a" $F)
	if [ $PERM -eq 755 ]; then
		echo "Press [Y/N] to change permission of $F to 744"
		read OPT
		TO_CHECK="Y"
		if [ "$OPT" == "$TO_CHECK" ]; then
			$(chmod 744 $F)
		fi
	fi
done
