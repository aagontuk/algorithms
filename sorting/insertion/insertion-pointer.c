#include <stdio.h>

void shift_elem(int i, int **sorted_arr);

int main(){
	int arr[10] = {9, 18, 7, 6, 15, 4, 3, 2, 11, 0};
	int len = 10;
	int i;

	int *sorted_arr[10];
	for(i = 0; i < len; i++){
		sorted_arr[i] = &arr[i];
	}

	/*
	 * Wired problem! Code works with following block
	 * But if I remove following block program crashes with
	 * segmentation fault!
	 */

	
	for(i = 0; i < len; i++){
		(i < len - 1) ? printf("%d, ", *sorted_arr[i]) : printf("%d\n", *sorted_arr[i]);
	}
	

	for(i = 0; i < len; i++){
		if(*sorted_arr[i] < *sorted_arr[i - 1]){
			shift_elem(i, sorted_arr);
		}
	}

	for(i = 0; i < len; i++){
		(i < len - 1) ? printf("%d, ", *sorted_arr[i]) : printf("%d\n", *sorted_arr[i]);
	}

	return 0;
}

void shift_elem(int i, int **sorted_arr){
	int *pin;

	for(pin = sorted_arr[i]; i && *sorted_arr[i - 1] > *pin; i--){
		sorted_arr[i] = sorted_arr[i - 1];
	}

	sorted_arr[i] = pin;
}
