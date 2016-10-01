#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "readintarray.h"

void readIntArray(int *array, int *n){
	char *str;
	char num[10];
	int numlen = 0;
	int len = 0;
	char prev = '\0', next = '\0';

	str = (char *) malloc(BUFFSIZE + 2);

    printf("Input integer array.\nExample: [5, 7, 0]\n\n>>> ");
    fgets(str, BUFFSIZE + 3, stdin);

    if(*str != '['){
		printf("Wrong Input! Should start with [\n");
		exit(1);
	}

	prev = *str;

	while(*(++str) != ']'){
		next = *(str + 1);

		if(prev == '['){			// first int

			if(*str != ','){
				
				if(isdigit(*str)){
					num[numlen++] = *str;
				}
				else{
					printf("Input should be a digit!\n");
					exit(2);
				}
			}
			else{
				num[numlen] = '\0';
				array[len++] = atoi(num);
				prev = *str;
				numlen = 0;
			}
		}

		else if(prev == ',' && *str == ' '){
			prev = *str;
		}

		else if(prev == ' ' && isdigit(*str)){
			num[numlen++] = *str;
		}

		else if(prev == ' ' && *str == ','){
			num[numlen] = '\0';
			array[len++] = atoi(num);
			prev = *str;
			numlen = 0;
		}

		else{
			printf("Invalid Input!\n");
			exit(2);
		}
	}
	
	num[numlen] = '\0';
	array[len++] = atoi(num);
	
	*n = len;
}
