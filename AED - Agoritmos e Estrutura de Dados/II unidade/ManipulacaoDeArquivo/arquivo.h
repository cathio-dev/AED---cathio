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

int ler(FILE *arq, char nomearq[]){
    char registro[50];
    arq=fopen(nomearq, "r");
    if(!arq) return 0;
    while(fgets(registro, sizeof(registro), arq)){
        printf("%s", registro);
    }
    fclose(arq);
    return 1;
}

int ler_formatado(FILE *arq, char nomearq[]){
    float nota1, nota2, nota3;
    arq=fopen(nomearq, "r");
    if(!arq) return 0;

    while(fscanf(arq, "%f %f %f", &nota1, &nota2, &nota3) != EOF){
        printf("Nota 1: %f, Nota 2: %f, Nota 3: %f", nota1, nota2, nota3);
    }
    fclose(arq);
    return 1;
}

int ler_alterar_geral(FILE *arq, char nomearq[]){
    float notas[3][3];
    char registro[20];
    int i = 0;
    arq=fopen(nomearq, "r");
    if(!arq) return 0;

    
    fclose(arq);
    return 1;
}
#endif