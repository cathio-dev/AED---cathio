#include <stdio.h>

int recbusca_binaria (int *V, int B, int ESQ, int DIR){ //algoritmo recursivo
    int meio;
    if(ESQ>DIR){ //se esquerda for maior que direita (nao achou item)
        return -1;
    }

    meio = (ESQ + DIR)/2;  //meio é a média aritimetica entre esquerda e direita 0 + 6/2 = 3

    if(V[meio]==B) return meio; //se o conteudo em meio conteudo em 3 for o item procurado, retorna a posição no meio.

    if(B<V[meio]){ //se o item for menor que o valor do conteudo em meio, faz recursividade, eliminando toda a parte direita. ESQ = 0, DIR agora é = 2, temos 0, 1, 2 restantes.
        return recbusca_binaria(V, B, ESQ, meio - 1);
    }else{              //se o item for maior, faremos o mesmo processo, só que ao contrário.
        return recbusca_binaria(V,B,meio+1,DIR);
    }


}

int busca_binaria (int *V, int K, int B){
    int ESQ, DIR, meio;
    ESQ=0; DIR=K-1;
    while(ESQ<=DIR){
        meio=(ESQ+DIR)/2;
        if(B==V[meio]){
            return meio;
        }else{
            if(B<V[meio]){
                DIR = meio-1;
            }else{
                ESQ = meio + 1;
            }
        }
    }
    return -1;
}

int main(){
    int V[]={1,2,7,8,15,20,30};
    int K = 7;
    int B = 15;
    int ESQ = 0;
    int DIR = 6;


    int elemento = busca_binaria(&V, K, B);
    int elementorec = recbusca_binaria (&V, B, ESQ, DIR);
    printf("%d\n", elemento);
    printf("\n%d", elementorec);

}

