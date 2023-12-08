//Trabalho Prático Programação 2021/2022
//Realizado por:
//Carlos Manuel Pascoal Pinto 2021155627

#include "stdio.h"

int posicaoajogar(char **tab, int modo, int tabuleiro, char ajogar) { //pergunta ao utilizador a posicao e retorna o valor
    int posicao = 0;
    if (modo == 2) {
        printf("jogador %c, em que posicao do tabuleiro %d gostaria de jogar?\n", ajogar, tabuleiro);
    } else if (modo == 1) {
        printf("Em que posicao do tabuleiro %d gostaria de jogar?\n", tabuleiro);
    }
    do {
        printf("->");
        scanf("%d", &posicao);
        if (tab[tabuleiro - 1][posicao - 1] != '-') {
            printf("posicao invalida\n");
            posicao = 0;
        }
    } while (posicao < 1 || posicao > 9);
    return posicao;
}


