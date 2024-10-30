#include <stdio.h>
#include <string.h>
#include "pilhachar.h"

int main(){
	tp_pilha pilha;
	tp_item e;
	char exp[1000];
	int valida = 0;
	inicializaPilha(&pilha);

	scanf("%[^\n]s", exp);
	int tam = strlen(exp);

	for(int i = 0; i < tam; i++){
		if(exp[i] == '('){
			e = exp[i];	
			push(&pilha, e);
		}

		if(exp[i] == ')'){

			if(!pilhaVazia(&pilha)){
				pop(&pilha, &e);
			}else{
				printf("\nincorrect");
				valida = 1;
				return 0;
			}
		}
	}

	if(valida = 1) return 0;

	if(pilhaVazia(&pilha))
		printf("\ncorrect");

	return 0;
}