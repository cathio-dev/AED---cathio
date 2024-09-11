#include "pilha.h"
#include <stdio.h>

int main(){
	
	tp_pilha pilha;
	tp_item e;
	inicializaPilha(&pilha);
	
	push(&pilha, 2);
	push(&pilha, 4);
	push(&pilha, 5);
	push(&pilha, 6);
	push(&pilha, 7);
	
	imprimePilha(pilha);
	
	
	return 0;
}