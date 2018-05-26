#!/bin/bash

#Sa se scrie un fisier de comenzi care va afisa toate fisierele dintr-un director si din subdirectoarele acestuia asupra carora au drepturi de scriere toate cele trei categorii de utilizatori. Aceste fisiere vor fi apoi redenumite, adaugandu-se sufixul .all (comenzi:  find -perm, mv).

for F in `find * . -type f`; do
	perm=`stat -c '%a' $F`
	if [ $perm -eq 700 ]; then
		echo $F
		dest='./test'
		cp $F -t $dest
		mv './test/'$F './test/'$F'.all'
	fi
done
