#include <stdio.h>
#include "filachar.h"
#include "pilhachar.h"
#include "pokemon.h"

typedef struct tp_jogador {
    char nome[20];
} jogador;

int main() {
	
    jogador j;
    tp_pokemon pokemons[15];
    iniciarPokemons(pokemons);
    int escolha1, escolha2, escolha3;
    
    printf("Bem-vindo ao POKÉ ROGUE!\n");
    printf("Digite seu nome, jogador: ");
    scanf("%s", j.nome);
    printf("\n");
    printf("\nAqui estão os pokemons disponíveis, %s:\n", j.nome);
    
    for (int i = 0; i < 15; i++) {
        printf("\nNome: %s\nTipo: %s\nVida: %d\nAtaque: %d\nDefesa: %d\nVelocidade: %d\n", pokemons[i].nome, pokemons[i].tipo, pokemons[i].vida, pokemons[i].ataque, pokemons[i].defesa, pokemons[i].velocidade);
    	
    	removeFila(&pokemons[i].habilidades, habilidade);
        printf("Habilidades: %s", habilidade);
    }
    //segunda etapa, empilhar os pokemóns que o jogador for escolher.
    tp_pilha pokemonsJogador;
    inicializaPilha(&pokemonsJogador);
    
    printf("\n========================================================\n");
    printf("Escolha três desses pokemóns, para compor o seu time!\n");
    
    printf("Primeira escolha: ");
    scanf("%d", &escolha1);
    push(&pokemonsJogador, pokemons[escolha1]);
    
    printf("\nSegunda escolha: ");
    scanf("%d", &escolha2);
    push(&pokemonsJogador, pokemons[escolha2]);
    
    printf("\nTerceira escolha: ");
    scanf("%d", &escolha3);
    push(&pokemonsJogador, pokemons[escolha3]);
    
    imprimePilha(pokemonsJogador);
    
	
	return 0;
}
