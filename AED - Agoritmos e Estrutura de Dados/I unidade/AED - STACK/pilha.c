#ifndef PILHA_H
#define PILHA_H
#include <stdio.h>
#define MAX 100

typedef int //mude para int ou char
  tp_item;// Declarei assim para ser mais facil de se quiser mudar o tipo de variavel da pilha.

typedef struct {
    int topo;
    tp_item item[MAX];
}tp_pilha;


void inicializaPilha (tp_pilha *p){
   p->topo = -1;//A variavel topo mostra onde esta o ultimo elemento da pilha, ja que so tem lixo no inicio, o topo é no espaço de memoria antes do inicio ddo vetor dos itens ou seja -1.
}

int pilhaVazia (tp_pilha *p){
  if(p->topo == -1) return 1;
  return 0;
}

int pilhaCheia(tp_pilha *p){
  if(p->topo == MAX-1) return 1;
  return 0;
}

int push(tp_pilha *p, tp_item e){
  if(pilhaCheia(p)) return 0;
    p->topo ++;
    p->item[p->topo] = e;
    return 1;
}

int pop (tp_pilha *p, tp_item *e){
  if (pilhaVazia(p)) return 0;
  *e = p->item[p->topo];
  p->topo--;
  return 1;
}

int top (tp_pilha *p, tp_item *e){
  if (pilhaVazia(p)) return 0;
  *e = p->item[p->topo];
  return 1;
}

void imprimirPilha(tp_pilha p){
  tp_item e;
  while(!pilhaVazia(&p)){
    pop(&p, &e);
     printf("\n");
    printf("%d", e);
  }
}

void retirarImpares(tp_pilha *p){
    tp_pilha paux;
    inicializaPilha(&paux);
    tp_item e;
    while(!pilhaVazia(p)){
        pop(p, &e);
        if(e % 2 == 0);
        push(&paux, e);
    }
    
    while(!pilhaVazia(&paux)){
        
        pop(&paux, &e);
        push(p, e);
    }
    
    
}

int comparaPilhas(tp_pilha p1, tp_pilha p2){
  if(tamanhoPilha(&p1) != tamanhoPilha(&p2)) return 0;

  tp_item e1, e2;

  while(!pilhaVazia(&p1)){ //enquanto a pilha estiver dando vazia, esvazie.
    pop(&p1, &e1);
    pop(&p2, &e2);
    if(e1!=e2) return 0;
  }
  return 1;

}

int empilhaPilha(tp_pilha *p1, tp_pilha *p2){
    if(alturaPilha(p1) + alturaPilha(p2) > MAX)
        return 0;
    tp_pilha paux;
    inicializaPilha(&paux);
    tp_item e;
    
    while(!pilhaVazia(p2)){
        pop(p2, &e);
        push(&paux, e);
        
    }
    
    while(!pilhaVazia(&paux)){
        
        pop(&paux, &e);
        push(p1, e);
        
    }
}



int alturaPilha(tp_pilha *p){
  return p->topo++;
}

# endif