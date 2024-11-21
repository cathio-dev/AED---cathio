#ifndef arquivo.H
#define arquivo.H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gravar(FILE *arq, char nomearq[]) //recebe ponteiro de tipo FILE, e o nome.
{
    char mensagem[30]; //char da mensagem
    arq = fopen(nomearq, "w"); //armazena no ponteiro, o endereço do FILE aberto com o nome do arquivo escolhido.
    if (!arq)
        return 0;
    printf("Digite a mensagem 1"); 
    fflush(stdin); //curar o gets
    gets(mensagem); //recebe a mensagem
    fprintf(arq, strcat(mensagem, "\n")); //pronta no arquivo a mensagem. (arquivo, mensagem)
    printf("Digite a mensagem 2");
    fflush(stdin);
    gets(mensagem);
    fputs(mensagem, arq);
    fclose(arq);
    return 1;
}

#endif