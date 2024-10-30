#include <stdio.h>
#include <string.h>
#include "pilhachar.h"

int main(){
	
	tp_item e;
	tp_pilha pilha;
	int correct = 0, incorrect = 0;
	int tam;
	char equacao[1000];
	
	while( scanf(" %s", &equacao) != EOF){
	 //le equacao
	inicializaPilha(&pilha); //cria a pilha os parenteses
	tam = strlen(equacao); //atribui tamanho para o for.
	
	for(int i = 0; i < tam; i++){
		
		if(equacao[i] == '('){
			
			e = equacao[i];
			push(&pilha, e);
		}
		
		if(equacao[i] == ')'){
			if(!pop(&pilha, &e)){ //significa que não temcomo popar pois não tem mais parenteses e nao esta igual
				incorrect = 1;
				break;
			}
		}
	}
	
	if(!pilhaVazia(&pilha) || incorrect == 1){
		printf("incorrect\n");
	}else{
		printf("correct\n");	
		}
		
		incorrect = 0; //adicionei o detalhe no final pois percebi que incorreto uma vez, ficaria pra sempre 1.
		correct = 0;
}
	
	
	return 0;
}