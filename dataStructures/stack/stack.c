#include <stdio.h>
#include <stdlib.h>

struct snode{
	struct snode *prev;
	int elem;
};

struct snode *top = NULL;

void push(int elem);
int pop(void);

int main(){
	char ch, fake;
	int elem;
	
	printf("Push?(u)\nPop?(p)\nQuit?(^D)\n>>> ");
	while((ch = getchar()) != EOF){
		scanf("%c", &fake);
		if(ch == 'u' || ch == 'U'){
			printf(">>> ");
			scanf("%d", &elem);
			scanf("%c", &fake);
			push(elem);
		}
		else{
			printf(">>> %d\n", pop());
		}
		printf("Push?(u)\nPop?(p)\nQuit?(^D)\n>>> ");
	}
	printf("\n");

	return 0;
}

void push(int elem){
	struct snode *new = (struct snode *)malloc(sizeof(struct snode));

	if(new){
		new->prev = top;
		new->elem = elem;
		top = new;
	}
	else{
		printf("Error allocating memory!\n");
	}
}

int pop(void){
	if(top){
		struct snode *ret = top;
		int elem = top->elem;
		top = ret->prev;
		free(ret);
		return elem;
	}
	else{
		return 0;
	}
}
