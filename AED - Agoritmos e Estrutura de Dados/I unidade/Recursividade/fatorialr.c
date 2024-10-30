#include <stdio.h>

int fatorialr(int num){ //com recursividade
    if(num==0){
        return 1;
    }else{
        return num * fatorialr(num-1);
    }
}

int fatorial(int num){
    int fat = 1;
    for(int i=num; i>=1; i--){
        fat=fat*i;
        return fat;
    }
}



int main(){
    int num;

    printf("Digite um número para ver o fatorial: ");
    scanf("%d", &num);
    printf("%d", fatorialr(num)); //podemos colocar com recursividade ou sem recursividade.



    return 0;
}