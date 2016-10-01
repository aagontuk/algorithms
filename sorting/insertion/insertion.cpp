#include <iostream>
#include "readintarray.h"
#include "printintarray.h"

void insertionSort(int *array, int len){
	int i, j, key;
	
	for(j = 1; j < len; j++){
		i = j - 1;
		key = array[j];

		while(i >= 0 && array[i] > key){
			array[i + 1] = array[i];
			i--;
		}

		array[i + 1] = key;
	}
}

int main(){
	int int_list[BUFFSIZE];
	int len;

	readIntArray(int_list, &len);
	insertionSort(int_list, len);
	printIntArray(int_list, len);

	return 0;
}


