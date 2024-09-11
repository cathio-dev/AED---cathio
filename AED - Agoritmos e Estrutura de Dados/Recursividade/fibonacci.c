#include <stdio.h>

int fibonaccir(int n){
    if( n==1 || n == 2) //fib = 1 ou fib = 2 -> o retorn vai ser 1
        return 1;
    
    return fibonaccir(n-2) + fibonaccir(n-1);
}

int main(){
    int n;

    printf("digite um número para colocar em fibonacci: ");
    scanf("%d", &n);
    printf("%d", fibonaccir(n));

    return 0;
}