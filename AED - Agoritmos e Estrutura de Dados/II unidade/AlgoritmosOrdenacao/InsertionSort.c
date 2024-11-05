#include <stdio.h>


void insercao(int *vet, int tam){
    int i, j, x;

    for (i=2; i<=tam; i++){
	    x = vet[i];
	    j=i-1;
	    vet[0] = x; 
    }

	while (x < vet[j]){
        vet[j+1] = vet[j];
        j--;
    }
    vet[j+1] = x;
}


int main(){
    int vet[]={4,7,8,3,6,1,2,5};
    int n=8;

    insercao(vet, n); //vetor e numero de elementos.
    
    for(int i=0; i<n; i++ ){
        if(i==7){
            printf("%d.", vet[7]);
            return 0;
        }
        printf("%d, ", vet[i]);
    }

}