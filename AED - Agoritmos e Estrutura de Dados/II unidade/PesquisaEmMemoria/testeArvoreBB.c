#include <stdio.h>
#include "ArvoreBinaria.h"

int main()
{
    tp_arvore *arvore = inicializa_arvore;

    // Inserir elementos na árvore
    insere_no(arvore, 10);
    insere_no(arvore, 5);
    insere_no(arvore, 15);
    insere_no(arvore, 3);
    insere_no(arvore, 7);

    if (arvore_vazia(arvore) == 1)
    {
        printf("Arvore vazia");
    }
    else
    {
        printf("Arvore conteudista");
    }

    em_ordem(arvore);
    /*// Exibir a árvore em ordem e a quantidade de nós
    printf("Árvore em ordem: ");
    em_ordem(arvore);
    //printf("\nQuantidade de nós: %d\n", arvore->quantidade);

    // Liberar memória
    destroi_arvore(arvore);*/

    return 0;
}