#ifndef PILHACHAR_H 
#define PILHACHAR_H
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef char tp_item[20];


typedef struct {
    int topo;
    tp_item item[MAX];  
} tp_pilha;


void inicializaPilha(tp_pilha *p) {
    p->topo = -1;
}

int pilhaVazia(tp_pilha *p){
  return p->topo == -1; // Retorna se a pilha está vazia
}


int push(tp_pilha *p, tp_item e) {
    if (p->topo == MAX - 1) {
        return 0;
    } else {
        p->topo++;
        strcpy(p->item[p->topo], e); 
        return 1;
    }
}


int pop(tp_pilha *p, tp_item e) {
    if (p->topo == -1) {
        return 0; 
    } else {
        strcpy(e, p->item[p->topo]); 
        p->topo--;
        return 1;
    }
}


int top(tp_pilha *p, tp_item e) {
    if (p->topo == -1) {
        return 0; 
    } else {
        strcpy(e, p->item[p->topo]);
        return 1;
    }
}

/*void imprimePilha(tp_pilha p){
  tp_item e;
  printf("\n");
  while (!pilhaVazia(&p)){
    pop(&p, &e);
    printf("%s\n", e); // Mudei para imprimir string
  }
}*/

#endif
