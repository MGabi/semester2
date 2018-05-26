#!/bin/bash

#4. Sa se scrie un fisier de comenzi care va afisa toate fisierele dintr-un director si din subdirectoarele acestuia asupra carora au drepturi de scriere toate cele trei categorii de utilizatori.
#Aceste fisiere vor fi apoi redenumite, adaugandu-se sufixul .all (comenzi: find -perm, mv)

for F in $(find . -perm -o+w); do #Fisierele ce pot fi scrise de toti
	echo $F
	mv $F $F".all"
done
