#!/bin/python2

def insertion_sort( l ):
	for j in range(1, len(l)):
		i = j - 1
		key = l[j]

		while (i >= 0 and l[i] > key):
			l[i + 1] = l[i]
			i = i - 1

		l[i + 1] = key

inp = raw_input("Enter integer list.\n>>> ")
int_list = [int(x) for x in inp.split(',')]
insertion_sort(int_list)
print int_list
