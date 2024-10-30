#include <stdio.h>
#include <string.h>
#include "pilhachar.h"

int main(){
    int N, tam, extracao; // casos, tamanho da escavacao, e a extracao de diamantes
    tp_item d; // lado esquerdo do diamante "<"
    tp_pilha p; // pilha de diamantes
    char escava[1000];

    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf(" %s", escava);  // lê a escavação
        tam = strlen(escava);
        inicializaPilha(&p);
        extracao = 0;  // reinicia a contagem de extrações para cada caso

        for (int j = 0; j < tam; j++) {
            if (escava[j] == '<') {
                d = escava[j];
                push(&p, d);  // empilha o símbolo "<"
            }

            if (escava[j] == '>') {
                if (pop(&p, &d)) {  // se possível desempilhar "<", forma um diamante
                    extracao++;
                }
            }
        }

        printf("Número de diamantes no caso %d: %d\n", i, extracao);  // imprime o número de extrações para o caso
    }

    return 0;
}
