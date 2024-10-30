#ifndef FILA_H
#define FILA_H
#include <stdio.h>
#define MAX 100

typedef char tp_item; //mudar dependendo do tipo do item.

typedef struct{
	tp_item item[MAX];
	int inicio, fim;
	// int len;
}tp_fila;

void inicializaFila(tp_fila *f){ //inicio e fim passam a ocupar a mesma posição física do vetor
	f->inicio = f->fim = MAX-1;
	//l->tam = 0;
}

int filaVazia(tp_fila *f){
	if(f->inicio == f->fim) return 1;
	return 0;
}

int proximo(int pos){
    if (pos == MAX - 1) return 0;
    pos++;
    return pos;
}

int filaCheia(tp_fila *f){
    if (proximo(f->fim) == f->inicio)
        return 1;
    return 0; 
}

int insereFila(tp_fila *f, tp_item e){
	if(filaCheia(f)){
		return 0;
	} else {
		f->fim = proximo(f->fim);
		f->item[f->fim] = e;
		return 1;
	}
}

int removeFila(tp_fila *f, tp_item *e){
    if(filaVazia(f))
        return 0;
    f->inicio = proximo(f->inicio);
    *e = f->item[f->inicio];
    //f->tam--
    return 1;

}

void imprimeFila(tp_fila f){
    tp_item e;
    while(!filaVazia(&f)){
        removeFila(&f, &e);
        printf("\n%d", e);
    }
}

#endif