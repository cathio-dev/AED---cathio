#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*1 interacao ===============================================

int main(){

    int *pc;
    pc = (int *) malloc(1);
    *pc = '69';
    printf("...%d.", *pc); //printa conteudo de pc.
    free(pc);
    pc = NULL;

    return 0;
}

----------------------------------------------------------*/

/*int main(){
    int *pi;
    pi = (int*) malloc(sizeof(int) * 5); //aloca um vetor de 5 posições, e o ponteiro está apontando para a primeira posição(deslocamento [0]).
    if(pi!=NULL){
        for(int i = 0; i < 5; i++){
            *(pi + i) = pow(i, 3); //varremos o vetor, passando inteiros, bytes de 4(100 -> 104...) e colocamos nessas posições os valores.
        }

        for(int i = 0; i < 5; i++){
            printf("\n...%d.", *(pi + i));
            free(pi); //limpa todo o vetor de 5 posições //DE LEI
            pi = NULL; //endereço apontando pra null     //DE LEI
        }
    }

    return 0;
}
*/