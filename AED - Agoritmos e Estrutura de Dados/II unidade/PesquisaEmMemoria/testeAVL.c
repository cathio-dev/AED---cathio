#include <stdio.h>
#include <locale.h>
#include "ArvoreAVL.h"

int main(){
    ArvAVL *arvore = criarAVL();

    
    inserir(arvore, 10);
    inserir(arvore, 1);
    inserir(arvore, 17);
    inserir(arvore, 28);
    inserir(arvore, 32);
    inserir(arvore, 42);

    if(estah_vaziaABB(arvore) == 1){

        printf("Está vazia");
    }else{
        printf("Tem conteudo");
    }

    printf("\n");

    preOrd(arvore);
    printf("\n");
    emOrd(arvore);
    printf("\n");
    posOrd(arvore);

    //desenheio no tablet, tudo funcionando



    return 0;
}