#include <stdio.h>
#include <stdlib.h>
#ifndef ArvoreBinaria.h
#define ArvoreBinaria.h

typedef int tp_item;

typedef struct tp_no{
    struct tp_no *esq;
    tp_item info;
    struct tp_no *dir;
}tp_no;

typedef struct tp_arvore {
tp_no *raiz;
int quantidade;
} tp_arvore;

tp_arvore* inicializa_arvore() {
tp_arvore* arvore = (tp_arvore*) malloc(sizeof(tp_arvore));
arvore->raiz = NULL;
arvore->quantidade = 0;
return arvore;
}

int arvore_vazia(tp_arvore *arvore) {
return (arvore->raiz == NULL);
}

tp_no *aloca_no() {
tp_no *no = (tp_no *)malloc(sizeof(tp_no));
return no;
}

int insere_no(tp_arvore *arvore, tp_item e) {
tp_no *pai = NULL, *novo, *p = arvore->raiz;
novo = aloca_no();
if (!novo) return 0;

novo->info = e;
novo->esq = NULL;
novo->dir = NULL;

while (p != NULL) {
    pai = p;
    if (e < p->info)
        p = p->esq;
    else
        p = p->dir;
}

if (pai != NULL) {
    if (e < pai->info)
        pai->esq = novo;
    else
        pai->dir = novo;
} else {
    arvore->raiz = novo;
}

arvore->quantidade++;
return 1;
}

void pre_ordem(tp_no *p){
    if(p!=NULL){
    printf("\n%d\n",p->info);
    pre_ordem(p->esq);                                                                  
    pre_ordem(p->dir);
    }
    
}
void em_ordem(tp_no *p){
     if(p!=NULL){
    em_ordem(p->esq); 
    printf("\n%d\n",p->info);
    em_ordem(p->dir);
    }
}
    void pos_ordem(tp_no *p){
    if(p!=NULL){
    pos_ordem(p->esq);                                                                  
    pos_ordem(p->dir);
     printf("\n%d\n",p->info);
    }
    
}
tp_no *busca_no(tp_no *p, tp_item e) {
while (p != NULL) {
if (e < p->info)
p = p->esq;
else if (e > p->info)
p = p->dir;
else
return p;
}
return NULL;
}

tp_no*  busca_noRec(tp_no *p, tp_item e){
    if(p!=NULL){
        if(e<p->info){
        busca_noRec(p->esq,e);
        }else if(e<p->info){
        busca_noRec(p->dir,e);
    }
    else return p;
        }
        else return NULL;
}

int altura_arvore(tp_no *raiz) {
    return (qntd_niveis(raiz) - 1);
}
    

int qntd_niveis(tp_no *raiz){
    if(raiz==NULL)return 0;
    int alt_esq= altura_arvore(raiz->esq)+1;
    int alt_dir= altura_arvore(raiz->dir)+1;
    if(alt_esq> alt_dir){
        return alt_esq;
    }else{
        return alt_dir;
    }
    
}


int qntd_nos(tp_no *p){
  int i=0;
  if(p!=NULL){
    i+=qntd_nos(p->esq);
    i++;
    i+=qntd_nos(p->dir);
  }
  return i;
}
int remove_no(tp_arvore *arvore, tp_item e) {
tp_no *p = arvore->raiz, *ant = NULL, *sub, *pai, *filho;
while (p != NULL && p->info != e) {
ant = p;
if (e < p->info)
p = p->esq;
else
p = p->dir;
}
if (p == NULL) return 0;

if (p->esq == NULL)
    sub = p->dir;
else if (p->dir == NULL)
    sub = p->esq;
else {
    pai = p; sub = p->dir; filho = sub->esq;
    while (filho != NULL) {
        pai = sub;
        sub = filho;
        filho = sub->esq;
    }
    if (pai != p) {
        pai->esq = sub->dir;
        sub->dir = p->dir;
    }
    sub->esq = p->esq;
}
if (ant == NULL)
    arvore->raiz = sub;
else if (p == ant->esq)
    ant->esq = sub;
else
    ant->dir = sub;

free(p);
arvore->quantidade--;
return 1;
}

void destroi_no(tp_no *no) {
if (no == NULL) return;
destroi_no(no->esq);
destroi_no(no->dir);
free(no);
}

void destroi_arvore(tp_arvore *arvore) {
destroi_no(arvore->raiz);
free(arvore);
}



#endif