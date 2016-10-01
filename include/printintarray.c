#include <stdio.h>
#include "printintarray.h"

void printIntArray(int *array, int len){
    int i;

    printf(">>> [");

    for(i = 0; i < len; i++){
        (i != (len - 1)) ? printf("%d, ", array[i]) : printf("%d", array[i]);
    }

	printf("]\n");
}

