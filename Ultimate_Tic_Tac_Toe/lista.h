//Trabalho Prático Programação 2021/2022
//Realizado por:
//Carlos Manuel Pascoal Pinto 2021155627

#include "stdio.h"

#ifndef JOGOGALO_LISTA_H
#define JOGOGALO_LISTA_H


typedef struct jogadas jog, *pjog;
struct jogadas {
    char jogador;
    int tabuleiro, posicao;
    pjog prox;
};

pjog novajog(char jogador, int tabuleiro, int posicao);

pjog adiciona(pjog lista, char jogador, int tabuleiro, int posicao);

void mostra_lista(pjog lista, int jogadasefetuadas, int njogadas);

void mostrardecisao(pjog lista, int jogadasefetuadas);

pjog recuperarjogo(char *fich, int *tam);

int isvazio(char *fich);

void guarda_lista(char *fich, struct jogadas *lista);

void escrevefich(FILE *f, pjog lista);

#endif //JOGOGALO_LISTA_H
