//Trabalho Prático Programação 2021/2022
//Realizado por:
//Carlos Manuel Pascoal Pinto 2021155627

#include <stdio.h>
#include <malloc.h>

#define N 9

char **tabvazia(int l, int c) //criaMat, alocar espaço
{
    char **tabela = NULL;
    tabela = malloc(sizeof(char *) * l);

    for (int h = 0; h < l; h++) {
        tabela[h] = malloc(sizeof(char *) * c);

    }

    return tabela;
}

void preenchetab(char **tabela) { //preenche a tabela com -
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tabela[i][j] = '-';
        }
    }
}

char jogada(char **p, int x, int y, char c) {//muda o tabuleiro inserindo o caracter correspondente ao jogador, troca o jogador e retorna o novo jogador
    x += -1;
    y += -1;
    p[x][y] = c;
    if (c == 'X') {
        c = 'O';
    } else {
        c = 'X';
    }
    return c;
}

void imprimetab(char **t) { //mostra o tabuleiro
    printf("\n");
    printf("   %c %c %c  |  %c %c %c  | %c %c %c \n", t[0][0], t[0][1], t[0][2], t[1][0], t[1][1], t[1][2], t[2][0],
           t[2][1], t[2][2]);
    printf("   %c %c %c  |  %c %c %c  | %c %c %c \n", t[0][3], t[0][4], t[0][5], t[1][3], t[1][4], t[1][5], t[2][3],
           t[2][4], t[2][5]);
    printf("   %c %c %c  |  %c %c %c  | %c %c %c \n", t[0][6], t[0][7], t[0][8], t[1][6], t[1][7], t[1][8], t[2][6],
           t[2][7], t[2][8]);
    printf("----------+---------+--------- \n");
    printf("   %c %c %c  |  %c %c %c  | %c %c %c \n", t[3][0], t[3][1], t[3][2], t[4][0], t[4][1], t[4][2], t[5][0],
           t[5][1], t[5][2]);
    printf("   %c %c %c  |  %c %c %c  | %c %c %c \n", t[3][3], t[3][4], t[3][5], t[4][3], t[4][4], t[4][5], t[5][3],
           t[5][4], t[5][5]);
    printf("   %c %c %c  |  %c %c %c  | %c %c %c \n", t[3][6], t[3][7], t[3][8], t[4][6], t[4][7], t[4][8], t[5][6],
           t[5][7], t[5][8]);
    printf("----------+---------+--------- \n");
    printf("   %c %c %c  |  %c %c %c  | %c %c %c \n", t[6][0], t[6][1], t[6][2], t[7][0], t[7][1], t[7][2], t[8][0],
           t[8][1], t[8][2]);
    printf("   %c %c %c  |  %c %c %c  | %c %c %c \n", t[6][3], t[6][4], t[6][5], t[7][3], t[7][4], t[7][5], t[8][3],
           t[8][4], t[8][5]);
    printf("   %c %c %c  |  %c %c %c  | %c %c %c \n", t[6][6], t[6][7], t[6][8], t[7][6], t[7][7], t[7][8], t[8][6],
           t[8][7], t[8][8]);
    printf("\n");
}

