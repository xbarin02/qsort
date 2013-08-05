#!/bin/bash

set -e

# list libc implementations
implementations=$(ls -1 impls/qsort_*.c |
                  perl -pe "s/impls\/qsort_(.*)\.c/\1/" |
		  sort)

# compile comparison counter
for impl in $implementations; do
    gcc -g impls/qsort_$impl.c cmp_count.c -o cmp_$impl
done

# run comparison counter
for dist in inc dec rand; do
    for impl in $implementations; do
	if [ -e ${dist}_$impl.dat ]; then
	    continue
	fi
	echo $dist $impl
	./cmp_${impl} $dist > ${dist}_$impl.dat || \
            (echo "fail $impl $dist" && rm ${dist}_$impl.dat)
    done
done

# graph the comparison count data
# (mangling the data was a paing in bash. hence python.)
python cmp_count_graphs.py
for f in *.p; do
    gnuplot $f
done
rm *.p
