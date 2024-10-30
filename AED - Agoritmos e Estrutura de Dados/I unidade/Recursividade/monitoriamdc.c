#include <stdio.h>
#include <string.h>

int MDCr(int n1, int n2){

    if(n1 % n2 == 0){
        return n2;
    }else{
        return MDCr(n2, n1 % n2);
    }
}

int main(){

    int num1, num2;
    int res;

    scanf("%d %d", &num1, &num2);
    res = MDCr(num1, num2);
    printf("%d", res);

    return 0;
}