/*
 * Queue - Array implementation
 * 
 * fron & count counters are used to keep track of the 
 * front and number of elements
 *
 * (front + count) % ARRSIZE is the enqueue element index.
 * Circular queue.
 * 
 */

#include <stdio.h>

#define BUFFSIZE 100

void enqueue(int elem);
int dequeue(void);

int queue[BUFFSIZE];
int front = 0, count = 0;

int main(){
	char ch, fake;
	int elem;

	printf("Menue:\n1. Enqueue?(e)\n2. Dequeue?(d)\n3. Exit?(^D)\n>>> ");
	while((ch = getchar()) != EOF){
		scanf("%c", &fake);
		if(ch == 'e' || ch == 'E'){
			printf(">>> ");
			scanf("%d%c", &elem, &fake);
			enqueue(elem);
		}
		else if(ch == 'd' || ch == 'D'){
			printf(">>> %d\n", dequeue());
		}
		else{
			printf(">>> Unknown entry \"%c\"\n", ch);
		}
		printf("Menue:\n1. Enqueue?(e)\n2. Dequeue?(d)\n3. Exit?(^D)\n>>> ");
	}
	printf("\n");

	return 0;
}

void enqueue(int elem){
	if(count < BUFFSIZE){
		queue[(front + count) % BUFFSIZE] = elem;
		count++;
	}
	else{
		printf("Queue full!\n");
	}
}

int dequeue(void){
	if(count > 0){
		if(front == 100){
			front = 0;
		}

		count--;

		return queue[front++];
	}
	else{
		return EOF;
	}
}


