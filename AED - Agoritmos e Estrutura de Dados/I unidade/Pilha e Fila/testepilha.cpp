#include <stdio.h>
#include "pilha.h"

#include "pilha.h"

int main() {
    tp_pilha pilha1, pilha2;
    tp_item elemento;

    // Inicializando as pilhas
    inicializaPilha(&pilha1);
    inicializaPilha(&pilha2);

    // Teste de empilhamento (push) na pilha1
    printf("Empilhando elementos na pilha1...\n");
    for(int i = 1; i <= 5; i++) {
        if (push(&pilha1, i)) {
            printf("Elemento %d empilhado na pilha1.\n", i);
        } else {
            printf("Falha ao empilhar o elemento %d na pilha1.\n", i);
        }
    }

    // Teste de desempilhamento (pop) da pilha1
    printf("\nDesempilhando elementos da pilha1...\n");
    while(!pilhaVazia(&pilha1)) {
        if (pop(&pilha1, &elemento)) {
            printf("Elemento %d desempilhado da pilha1.\n", elemento);
        } else {
            printf("Falha ao desempilhar.\n");
        }
    }

    // Empilhando elementos em pilha2
    printf("\nEmpilhando elementos na pilha2...\n");
    for(int i = 10; i <= 15; i++) {
        push(&pilha2, i);
    }

    // Testando a função de impressão da pilha2
    printf("\nImprimindo a pilha2:\n");
    imprimePilha(pilha2);

    return 0;
}
