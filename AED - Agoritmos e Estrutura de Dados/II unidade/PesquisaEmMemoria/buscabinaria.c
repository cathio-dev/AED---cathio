#include <stdio.h>

int recbusca_binaria (int *V, int B, int ESQ, int DIR){
    int meio;
    if(ESQ>DIR){
        return -1;
    }

    meio = (ESQ + DIR)/2;

    if(V[meio]==B) return meio;

    if(B<V[meio]){
        return recbusca_binaria(V, B, ESQ, meio - 1);
    }else{
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

