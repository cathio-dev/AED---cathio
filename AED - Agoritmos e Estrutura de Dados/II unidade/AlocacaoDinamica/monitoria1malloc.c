#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p;
    p = (int *)malloc(sizeof(int)); //alocação de um bloco com o tamanho de memória de o byte do inteiro, que são 4 bytes.
    *p = 5; //conteudo de onde o ponteiro aponta (que é a memória alocada)

    printf("..%d.", *p);

}