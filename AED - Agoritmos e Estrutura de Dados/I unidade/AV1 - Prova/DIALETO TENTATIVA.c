#include <stdio.h>
#include <string.h>
#include "pilhachar.h"
#include "filachar.h"

int main(){
	
	tp_pilha pd; //pilha das letras dialeto
	tp_item LE; //letras da esquerda
	inicializaPilha(&pd);
	
	tp_fila filaString; //fila referência, da pilha esquerda.
	tp_item LD; //letas direitas
	tp_item lixo;

	inicializaFila(&filaString);
	int validaChar = 1;
	char palavra[1000];
	int tam;
	//char d, e, f; 
	
	printf("Insira uma palavra para verificar se está ou não no dialeto: ");
	scanf("%s", &palavra);
	
	tam = strlen(palavra); //exemplo dffeffd

	for(int j = 0; j < tam; j++){

		LE = palavra[j];
		insereFila(&filaString, LE); //insere dffeffd na fila
	}
	
	for(int i = 0; i < tam; i++){

		if(palavra[i] != 'd' && palavra[i] != 'e' && palavra[i] != 'f') {
    		printf("Não está no dialeto, reinicie o código e tente novamente.");
    		return 0;
		
		}
		
		if( palavra[i] == 'f' || palavra[i] == 'd'){ //d
			
			LE = palavra[i]; //
			push(&pd, LE); //dff fica em ordem cima baixo ffd empilhado.
			removeFila(&filaString, &lixo); // effd

		}
		
		//ate agora temos a pilha com ffd, e a fila com effd sobrando, pois no E, acaba
		if(palavra[i] == 'e'){

			removeFila(&filaString, &lixo); //fica ffd

			while(!pilhaVazia(&pd)){

				pop(&pd, &LE); // ffd // 1 = f
				removeFila(&filaString, &LD); //ffd //1 = f

				if(LD == LE){ //1 - f = f correto
					printf("A palavra está no dialeto.");
					return 0;
				}else{
					validaChar = 0;

					if(validaChar = 0){
						printf("A palavra não está no dialeto.");
						return 0;
					}
				}
			}
		}
	}
	
	return 0;
}