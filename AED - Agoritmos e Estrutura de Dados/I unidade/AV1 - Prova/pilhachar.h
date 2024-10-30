#ifndef PILHA_H //if not define
#define PILHA_H
#include <stdio.h>
#define MAX 100

typedef char // Mudei de int para char.
  tp_item;

typedef struct {
  int topo;
  tp_item item[MAX];
} tp_pilha;

void inicializaPilha(tp_pilha *p){
  p->topo = -1;
}

int pilhaVazia(tp_pilha *p){
  return p->topo == -1; // Retorna se a pilha está vazia
}

int pilhaCheia(tp_pilha *p){
  return p->topo == MAX-1; // Retorna se a pilha está cheia
}

int push(tp_pilha *p, tp_item e){
  if(pilhaCheia(p)) return 0; // Aborta a função se a pilha estiver cheia
  p->topo++; // Aumenta o topo
  p->item[p->topo] = e; // Guarda o elemento no topo
  return 1;
}

int pop(tp_pilha *p, tp_item *e){
  if (pilhaVazia(p)) return 0; // Retorna 0 se a pilha estiver vazia
  *e = p->item[p->topo]; // Coloca o item no endereço de e
  p->topo--; // Decrementa o topo
  return 1;
}

int top(tp_pilha *p, tp_item *e){
  if(pilhaVazia(p)) return 0; // Verifica se a pilha está vazia
  *e = p->item[p->topo]; // Retorna o item no topo sem removê-lo
  return 1;
}

void imprimePilha(tp_pilha p){
  tp_item e;
  printf("\n");
  while (!pilhaVazia(&p)){
    pop(&p, &e);
    printf("%c\n", e); // Mudei para imprimir char
  }
}

int alturaPilha(tp_pilha *p){
  return p->topo + 1;
}

/*void retiraImparesM(tp_pilha *p){ // Continua o mesmo, mas ajustado para chars
	tp_pilha paux;
	inicializaPilha(&paux);
	tp_item e;
	while(!pilhaVazia(p)){
		pop(p, &e); 
		if(e % 2 == 0){ // Se for par, mantemos na pilha
			push(&paux, e); 
		}
	}
	
	while(!pilhaVazia(&paux)){
		pop(&paux, &e); 
		push(p, e);
	}
}*/

/*void retirarImpares(tp_pilha *p){ // Função para números, pode não ser usada para chars
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
}*/

/*int comparaPilhas(tp_pilha p1, tp_pilha p2){
  if(alturaPilha(&p1) != alturaPilha(&p2)) return 0;

  tp_item e1, e2;

  while(!pilhaVazia(&p1)){ 
    pop(&p1, &e1);
    pop(&p2, &e2);
    if(e1 != e2) return 0;
  }
  return 1;
}*/

/*int empilhaPilha(tp_pilha *p1, tp_pilha *p2){
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
}*/

#endif // Fim do ifndef
