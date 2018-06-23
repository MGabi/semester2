#!/bin/bash

for f in `cat $1`; do
	if grep ^[A-Z]; then
		echo $f
	fi
done
