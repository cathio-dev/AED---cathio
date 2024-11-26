#include <stdio.h>
#include "ArvoreBinaria.h"
int main(){
    
tp_arvore *arv;
arv=inicializa_arvore();
    int esc=0,e,elem;

do{
    printf("escolha uma opção:\n1- inserir\n2-printar\n3-buscar\n4-buscarec\n5-quant nos\n6-altura\n7-quant niveis\n8-remove no\n9-destroi arvore\n10-sair\n");
    scanf("%d",&esc);
    
    switch (esc) {
        case 1:
        printf("digite o valor a ser inserido:");
        scanf("%d",&e);
        insere_no(arv,e);
        
        break;
         case 2:
         
         printf("pre ordem: ");
         pre_ordem(arv->raiz);
         printf("\n");
         printf("em ordem: ");
         em_ordem(arv->raiz);
         printf("\n");
         printf("pos ordem: ");
         pos_ordem(arv->raiz);
         
         break;
         
        case 3:
        scanf("%d",&elem);
       if (busca_no(arv->raiz,elem))
       printf("achei\n");
       else printf("nada\n");
        break;
        
        case 4:
        scanf("%d",&elem);
       if (busca_noRec(arv->raiz,elem))
       printf("achei\n");
       else printf("nada\n");
        break;
        
        case 5:
        printf("%d\n",qntd_nos(arv->raiz));
        break;
        
        case 6:
        printf("%d\n",altura_arvore(arv->raiz));
        break;
        
        case 7:
        printf("%d\n",qntd_niveis(arv->raiz));
        break;
        
         case 8:
       scanf("%d",&elem);
        remove_no(arv,elem);
        break;
        
        case 9:
        destroi_arvore(arv);
        break;
        
        default:
        scanf("%d",&esc);
        
    }
    
}while(esc != 10);

return 0;

}

