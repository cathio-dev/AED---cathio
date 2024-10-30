#ifndef PILHA_H //if not define
#define PILHA_H
#include <stdio.h>
#define MAX 100


typedef int //mudar dependendo do tipo trabalhado.
  tp_item;

typedef struct {
  int topo;
  tp_item item[MAX];
} tp_pilha;


void inicializaPilha(tp_pilha *p){
  p->topo = -1;
}

int pilhaVazia(tp_pilha *p){
  if (p->topo == -1)  return 1; //verdadeiro, pilha esta vazia
  return 0; //falso, pilha nao esta vazia
}

int pilhaCheia(tp_pilha *p){
  if(p->topo == MAX-1) {
    return 1;
  } else {
    return 0;
  }
}

int push(tp_pilha *p, tp_item e){
  if(pilhaCheia(p)==1) return 0; //testa se a pilha esteja cheia, aborta a funcao caso esteja
  p->topo++; //aumenta o topo
  p->item[p->topo] = e; //guarda o elemento no vetor na posicao topo
  return 1;
}

int pop(tp_pilha *p, tp_item *e){
  if (pilhaVazia(p)) return 0; //retorna 0 caso a pilha estiver vazia
  *e = p->item[p->topo]; //joga o item para a variavel e (que deve ser criada na main)
  p->topo--;
  return 1;
}

int top(tp_pilha *p, tp_item *e){ //incompleta

  if(pilhaVazia(p))
    return 0;
  
  *e = p->item[p->topo];
  return 1;
  
}
  
void imprimePilha(tp_pilha p){
  tp_item e;
  printf("\n");
  while (!pilhaVazia(&p)){
    pop(&p, &e);
    printf("%d", e);
    printf("\n");
  }
  
}

int alturaPilha(tp_pilha *p){
  return p->topo+1;
}


void retiraImparesM(tp_pilha *p){
	tp_pilha paux;
	inicializaPilha(&paux);
	tp_item e;
	while(!pilhaVazia(p)){
		pop(p, &e); //nao passamos endereço de memoria, pois nao queremos afetar a verdadeira
		if(e % 2 == 0){ //quer dizer que é par, colocamos na auxiliar para depois recolocar
			push(&paux, e); //ta com todos os pares
		}
	}
	
	while(!pilhaVazia(&paux)){
		pop(&paux, &e); //começa a tirar os pares, e vamos colocá-los devolta na p principal.
		push(p, e); //adicionei pontovirgula
	}
}

void retirarImpares(tp_pilha *p){
    tp_pilha paux;
    inicializaPilha(&paux);
    tp_item e;
    while(!pilhaVazia(p)){
        pop(p, &e); //
        if(e % 2 == 0);
        push(&paux, e);
    }
    
    while(!pilhaVazia(&paux)){
        
        pop(&paux, &e);
        push(p, e);
    }
    
    
}

int comparaPilhas(tp_pilha p1, tp_pilha p2){
  if(alturaPilha(&p1) != alturaPilha(&p2)) return 0;

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

#endif //fim do ifndef 