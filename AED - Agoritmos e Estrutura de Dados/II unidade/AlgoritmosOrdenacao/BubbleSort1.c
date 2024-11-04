#include <stdio.h>

void bubblesort1(int *v, int n)
{
int aux, i, j;
for (i=0; i<n-1; i++) /* controla o número de passagens */
    for (j=0; j<n-1-i; j++) /* controla cada passagem */
        if (v[j] > v[j+1]) { /* elementos fora de ordem trocar */
            aux=v[j];
            v[j]=v[j+1];        /* troca de elementos */
            v[j+1]=aux;
        }
}

int main(){
    int vet[]={4,7,8,3,6,1,2,5};
    int n=8;

    bubblesort1(vet, n); //vetor e numero de elementos.
    
    for(int i=0; i<n; i++ ){
        if(i==7){
            printf("%d.", vet[7]);
            return 0;
        }
        printf("%d, ", vet[i]);
    }

}
