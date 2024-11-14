#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H
#include <stdio.h>
#include <stdlib.h>


typedef int tp_item;

typedef struct tp_no{
    struct tp_no *esq;
    tp_item info;
    struct tp_no *dir;
}tp_no;

typedef tp_no *tp_arvore;

tp_arvore inicializa_arvore(){
    return NULL;
}

int arvore_vazia(tp_arvore raiz){
    if(raiz==NULL) return 1;
    else return 0;
}

tp_no *aloca_no(){
    tp_no *no;
    no=(tp_no*)malloc(sizeof(tp_no));
    return no;
}

int insere_no(tp_arvore *raiz, tp_item e){
    tp_no *pai = NULL, *novo, *p=*raiz;
    novo=aloca_no();
    if(!novo) return 0;

    novo->info=e;
    novo->esq=NULL;
    novo->dir=NULL;
    while(p!=NULL){
        pai=p;
        if( e < p-> info)
            p=p->esq;
        else
            p=p->dir;
    }

    if(pai != NULL){
        if(e < pai->info)
            pai->esq=novo;
        else
            pai -> dir = novo;
    }else{
        *raiz = novo;
        return 1;
    }
}

void pre_ordem(tp_no *p){
    if(p!=NULL){
        printf("\n%d\n", p->info); //visita antes o no, depois esq, dps direita. começa imprimindo o pai.
        pre_ordem(p->esq);
        pre_ordem(p->dir);

    }
}
void pre_ordem(tp_no *p){
    if(p!=NULL){
        printf("\n%d\n", p->info); //visita antes o no, depois esq, dps direita. começa imprimindo o pai.
        pre_ordem(p->esq);
        pre_ordem(p->dir);

    }
}

void em_ordem(tp_no *p){
    if(p!=NULL){
        em_ordem(p->esq);
        printf("\n%d\n", p->info); //visita antes o no, depois esq, dps direita. começa imprimindo o pai.
        em_ordem(p->dir);

    }
}

void pos_ordem(tp_no *p){
    if(p!=NULL){
        pos_ordem(p->esq);
        pos_ordem(p->dir);
        printf("\n%d\n", p->info); //visita antes o no, depois esq, dps direita. começa imprimindo o pai.
    }
}

tp_no* busca_no (tp_no *p, tp_item e){
    while (p != NULL){ //enquanto no pai for dferente que null
        if(e<p->info) //se o elemento for menor que o no, o iremos para o no da esquerda. repetimos. Entramos no nó da esquerda;
            p=p->esq;
        else            //se for maior, vamos para o filho da direita.
            if(e>p->info)       
                p = p->dir;
            else                //se for igual, retornamos o próprio nó. que será o nó do topo.
                return p;      //retornamos o p.
    }
    return (NULL);
    
}

int qnt_niveis(tp_arvore raiz){
    if(raiz == NULL) return 0;
    int alt_esq = qnt_niveis(raiz -> esq);
    int alt_dir = qnt_niveis(raiz -> dir);
    if(alt_esq > alt_dir){
        return alt_esq + 1;
    }else{
        return alt_dir + 1;
    }
}

int altura_arvore(tp_arvore raiz){
    return (qnt_niveis(raiz) - 1);
}

/***** Fila *****/

typedef struct tp_fila {
	tp_no *no;
	struct tp_fila *prox;	
} tp_fila;

tp_fila * inicia_fila() {
	return NULL;
}

int fila_vazia(tp_fila **fila) {
	if(*fila == NULL) return 1;
	return 0;
}

tp_fila * aloca_fila(tp_no *no) {
	tp_fila *no_fila = (tp_fila*) malloc(sizeof(tp_fila));
	no_fila->no = no;
	no_fila->prox = NULL;
	return no_fila;
}

int insere_fila(tp_fila **fila, tp_no *no) {
	tp_fila *no_fila = aloca_fila(no), *atu = *fila;
	if(no_fila == NULL) return 0;
	
	if(fila_vazia(fila)) *fila = no_fila;
	else {
		while(atu->prox != NULL) {
			atu = atu->prox;
		}
		atu->prox = no_fila;
	}
	return 1;
}

tp_no * remove_fila(tp_fila **fila) {
	tp_fila *atu = *fila;
	*fila = atu->prox;
	tp_no *no = atu->no;
	free(atu);
	atu = NULL;
	return no;
}

void imprime_fila(tp_fila **fila) {
	tp_fila *atu = *fila;
	while(atu != NULL) {
		printf("%d ", atu->no->info);
		atu = atu->prox;
	}
	printf("\n");
}

void destroi_fila(tp_fila **fila) {
	tp_fila *atu = *fila;
	while(atu != NULL) {
		*fila = atu->prox;
		free(atu);
		atu = *fila;
	}
	*fila = NULL;
}


void BFS(tp_arvore *raiz) {
    if(!arvore_vazia(*raiz)) {
        tp_fila *fila = inicia_fila();
        insereFila(&fila, *raiz);

	    while(!fila_vazia(&fila)) {
		    tp_no *no = remove_fila(&fila);
		    printf("%d ", no->info);
		
		    if(no->esq != NULL) insere_fila(&fila, no->esq);
		    if(no->dir != NULL) insere_fila(&fila, no->dir);
	    }
	destroi_fila(&fila);
    }
}

/***** Fila *****/

typedef struct tp_fila {
	tp_no *no;
	struct tp_fila *prox;	
} tp_fila;

tp_fila * inicia_fila() {
	return NULL;
}

int fila_vazia(tp_fila **fila) {
	if(*fila == NULL) return 1;
	return 0;
}

tp_fila * aloca_fila(tp_no *no) {
	tp_fila *no_fila = (tp_fila*) malloc(sizeof(tp_fila));
	no_fila->no = no;
	no_fila->prox = NULL;
	return no_fila;
}

int insere_fila(tp_fila **fila, tp_no *no) {
	tp_fila *no_fila = aloca_fila(no), *atu = *fila;
	if(no_fila == NULL) return 0;
	
	if(fila_vazia(fila)) *fila = no_fila;
	else {
		while(atu->prox != NULL) {
			atu = atu->prox;
		}
		atu->prox = no_fila;
	}
	return 1;
}

tp_no * remove_fila(tp_fila **fila) {
	tp_fila *atu = *fila;
	*fila = atu->prox;
	tp_no *no = atu->no;
	free(atu);
	atu = NULL;
	return no;
}

void imprime_fila(tp_fila **fila) {
	tp_fila *atu = *fila;
	while(atu != NULL) {
		printf("%d ", atu->no->info);
		atu = atu->prox;
	}
	printf("\n");
}

void destroi_fila(tp_fila **fila) {
	tp_fila *atu = *fila;
	while(atu != NULL) {
		*fila = atu->prox;
		free(atu);
		atu = *fila;
	}
	*fila = NULL;
}



#endif
