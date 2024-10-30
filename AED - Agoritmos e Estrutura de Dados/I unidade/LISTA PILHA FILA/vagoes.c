//3) Considere a operação de organização de um trem onde os vagões transportam três
//tipos de cargas A, B e C. O objetivo do programa de controle a ser projetado é montar um
//comboio com os vagões organizados por tipo de carga, agrupando aqueles do mesmo tipo,
//utilizando para isso um desvio da linha férrea como mostrado na figura seguir. Após a
//atuação do sistema, partindo da situação inicial (a), o trem terá os vagões organizados
//como a situação final (c). Uma das situações intermediárias durante o processo é
//mostrada na figura (b)



#include <stdio.h>
#include "fila.h"
#include "pilha.h"

int main(){
	tp_fila trem;
	tp_pilha desvio;
	tp_item e;
	inicializaFila(tp_fila &trem);
	inicializaPilha(tp_pilha &desvio);
	
	
	
	insereFila(&trem, A);
	insereFila(&trem, B);
	insereFila(&trem, C);
	insereFila(&trem, A);
	insereFila(&trem, C);
	insereFila(&trem, B);
	insereFila(&trem, C);
	insereFila(&trem, B);
	
	return 0;
}