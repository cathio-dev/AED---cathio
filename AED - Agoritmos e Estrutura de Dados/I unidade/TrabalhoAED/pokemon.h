#include <stdio.h>
#include "pilhachar.h"
#include "filachar.h"
#include <string.h>
#ifndef POKEMON_H
#define POKEMON_H

tp_item PoisonPoint, SandVeil, Static, Intimidate, RunAway, KeenEye, ToughClaws, ShedSkin, ShieldDust, Torrent, Blaze, Overgrow;

typedef struct {
    char nome[20];
    int vida;
    int ataque;
    int defesa;
    int velocidade;
    char tipo[20];
    tp_fila habilidades;
} tp_pokemon;


//me baseei na lógica de suymito e criei uma função para iniciar os pokemóns
void iniciarPokemons(tp_pokemon pokemons[]) {
	
	//para a categorização dos pokemóns usei essa pokedex: https://ydarissep.github.io/PokeRogue-Pokedex/?table=speciesTable&
	//e segui a ordem da lista


    // Poke - 1
    strcpy(pokemons[0].nome, "Bulbassaur");
    strcpy(pokemons[0].tipo, "Grass/Poison");
    pokemons[0].vida = 45;
    pokemons[0].ataque = 49;
    pokemons[0].defesa = 49;
    pokemons[0].velocidade = 45;
    
    //iniciei a fila e coloquei habilidades, e cada fila tem uma posição para percorrermos o vetor no print
    inicializaFila(&pokemons[0].habilidades);
    insereFila(&pokemons[0].habilidades, Overgrow);

    // Poke - 2
    strcpy(pokemons[1].nome, "Charmander");
    strcpy(pokemons[1].tipo, "Fire");
    pokemons[1].vida = 39;
    pokemons[1].ataque = 52;
    pokemons[1].defesa = 43;
    pokemons[1].velocidade = 65;
    
    inicializaFila(&pokemons[1].habilidades);
    insereFila(&pokemons[1].habilidades, Blaze);

    // Poke - 3
    strcpy(pokemons[2].nome, "Squirtle");
    strcpy(pokemons[2].tipo, "Water");
    pokemons[2].vida = 44;
    pokemons[2].ataque = 48;
    pokemons[2].defesa = 65;
    pokemons[2].velocidade = 43;
    
    inicializaFila(&pokemons[2].habilidades);
    insereFila(&pokemons[2].habilidades, Torrent);

    // Poke - 4
    strcpy(pokemons[3].nome, "Caterpie");
    strcpy(pokemons[3].tipo, "Bug");
    pokemons[3].vida = 45;
    pokemons[3].ataque = 30;
    pokemons[3].defesa = 35;
    pokemons[3].velocidade = 45;

    inicializaFila(&pokemons[3].habilidades);
    insereFila(&pokemons[3].habilidades, ShieldDust);

    // Poke - 5
    strcpy(pokemons[4].nome, "Weedle");
    strcpy(pokemons[4].tipo, "Bug/Poison");
    pokemons[4].vida = 40;
    pokemons[4].ataque = 35;
    pokemons[4].defesa = 30;
    pokemons[4].velocidade = 50;
    
    inicializaFila(&pokemons[4].habilidades);
    insereFila(&pokemons[4].habilidades, ShieldDust);
    
    // Poke - 6
	strcpy(pokemons[5].nome, "Kakuna");
	strcpy(pokemons[5].tipo, "Bug/Poison");
	pokemons[5].vida = 45;
	pokemons[5].ataque = 25;
	pokemons[5].defesa = 50;
	pokemons[5].velocidade = 35;

	inicializaFila(&pokemons[5].habilidades);
	insereFila(&pokemons[5].habilidades, ShedSkin);
	
	// Poke - 7 - Coloquei porque gosto dele
	strcpy(pokemons[6].nome, "Meowth");
	strcpy(pokemons[6].tipo, "Normal");
	pokemons[6].vida = 45;
	pokemons[6].ataque = 25;
	pokemons[6].defesa = 50;
	pokemons[6].velocidade = 35;

	inicializaFila(&pokemons[6].habilidades);
	insereFila(&pokemons[6].habilidades, ToughClaws);
	
	
	

	//Poke - 8
	strcpy(pokemons[7].nome, "Pidgey");
	strcpy(pokemons[7].tipo, "Normal/Flying");
	pokemons[7].vida = 40;
	pokemons[7].ataque = 45;
	pokemons[7].defesa = 40;
	pokemons[7].velocidade = 56;

	inicializaFila(&pokemons[7].habilidades);
	insereFila(&pokemons[7].habilidades, KeenEye);

	//Poke - 9
	strcpy(pokemons[8].nome, "Rattata");
	strcpy(pokemons[8].tipo, "Normal");
	pokemons[8].vida = 30;
	pokemons[8].ataque = 56;
	pokemons[8].defesa = 35;
	pokemons[8].velocidade = 72;

	inicializaFila(&pokemons[8].habilidades);
	insereFila(&pokemons[8].habilidades, RunAway);

	// Poke - 10
	strcpy(pokemons[9].nome, "Spearow");
	strcpy(pokemons[9].tipo, "Normal/Flying");
	pokemons[9].vida = 40;
	pokemons[9].ataque = 60;
	pokemons[9].defesa = 30;
	pokemons[9].velocidade = 70;

	inicializaFila(&pokemons[9].habilidades);
	insereFila(&pokemons[9].habilidades, KeenEye);

	// Poke - 11
	strcpy(pokemons[10].nome, "Ekans");
	strcpy(pokemons[10].tipo, "Poison");
	pokemons[10].vida = 35;
	pokemons[10].ataque = 60;
	pokemons[10].defesa = 44;
	pokemons[10].velocidade = 55;

	inicializaFila(&pokemons[10].habilidades);
	insereFila(&pokemons[10].habilidades, Intimidate);

// Poke - 12
strcpy(pokemons[11].nome, "Pikachu");
strcpy(pokemons[11].tipo, "Electric");
pokemons[11].vida = 35;
pokemons[11].ataque = 55;
pokemons[11].defesa = 40;
pokemons[11].velocidade = 90;

inicializaFila(&pokemons[11].habilidades);
insereFila(&pokemons[11].habilidades, Static);

// Poke - 13
strcpy(pokemons[12].nome, "Sandshrew");
strcpy(pokemons[12].tipo, "Ground");
pokemons[12].vida = 50;
pokemons[12].ataque = 75;
pokemons[12].defesa = 85;
pokemons[12].velocidade = 40;

inicializaFila(&pokemons[12].habilidades);
insereFila(&pokemons[12].habilidades, SandVeil);

// Poke - 14
strcpy(pokemons[13].nome, "Nidoran♂");
strcpy(pokemons[13].tipo, "Poison");
pokemons[13].vida = 46;
pokemons[13].ataque = 57;
pokemons[13].defesa = 40;
pokemons[13].velocidade = 50;

inicializaFila(&pokemons[13].habilidades);
insereFila(&pokemons[13].habilidades, PoisonPoint);

// Poke - 15
strcpy(pokemons[14].nome, "Nidoran♀");
strcpy(pokemons[14].tipo, "Poison");
pokemons[14].vida = 55;
pokemons[14].ataque = 47;
pokemons[14].defesa = 52;
pokemons[14].velocidade = 41;

inicializaFila(&pokemons[14].habilidades);
insereFila(&pokemons[14].habilidades, PoisonPoint); //erro da frase separada

}

#endif

