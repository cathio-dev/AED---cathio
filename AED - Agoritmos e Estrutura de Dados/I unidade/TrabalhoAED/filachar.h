#ifndef FILACHAR_H
#define FILACHAR_H
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef char tp_item[20]; 

typedef struct {
    tp_item item[MAX];
    int inicio, fim;
} tp_fila;

void inicializaFila(tp_fila *f) {
    f->inicio = f->fim = MAX - 1;
}

int filaVazia(tp_fila *f) {
    return f->inicio == f->fim;
}

int proximo(int pos) {
    return (pos == MAX - 1) ? 0 : pos + 1;
}

int filaCheia(tp_fila *f) {
    return proximo(f->fim) == f->inicio;
}

int insereFila(tp_fila *f, tp_item e) {
    if (filaCheia(f)) {
        return 0;
    } else {
        f->fim = proximo(f->fim);
        strcpy(f->item[f->fim], e);
        return 1;
    }
}

int removeFila(tp_fila *f, tp_item e) {
    if (filaVazia(f)) {
        return 0;
    } else {
        f->inicio = proximo(f->inicio);
        strcpy(e, f->item[f->inicio]);
        return 1;
    }
}

#endif
