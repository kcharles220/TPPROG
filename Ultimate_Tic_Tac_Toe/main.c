//Trabalho Prático Programação 2021/2022
//Realizado por:
//Carlos Manuel Pascoal Pinto 2021155627

#include "stdlib.h"
#include <stdio.h>
#include "imprimetab.h"
#include "vencedor.h"
#include "bot.h"
#include "lista.h"
#include "jogo.h"

#define FICHBIN "jogo.bin"
#define N 9

int main() {
    FILE *fp = fopen(FICHBIN, "r");
    int existe = 0;
    if (fp != NULL) {
        existe = 1;
        fclose(fp);
    }
    pjog lista = NULL;
    pjog listarecuperada = NULL;
    char **tab = tabvazia(N, N);
    preenchetab(tab);
    int mododejogo = 0, tabuleiro = 0, posicao, jogadasefetuadas = 0, tam = 0, controlo = 0;
    char ajogar = 'X', vencedor[N], ovencedor = ' ', dec = ' ';
    for (int i = 0; i < N; ++i) {
        vencedor[i] = ' ';
    }
    printf("Selecione o modo de jogo:\n");
    printf(" Jogador VS Computador  (1)\n");
    printf(" Jogador VS Jogador     (2)\n");
    do {
        printf("->");
        scanf("%d", &mododejogo);
    } while (mododejogo != 1 && mododejogo != 2);
    if (isvazio(FICHBIN) != 1 && existe == 1) {
        printf("Deseja retomar o jogo anterior?(Y/N)\n");
        do {
            printf("->");
            scanf(" %c", &dec);
        } while (dec != 'Y' && dec != 'N' && dec != 'y' && dec != 'n');
        if (dec == 'Y' || dec == 'y') {
            listarecuperada = recuperarjogo(FICHBIN, &tam);
            do {
                if (controlo != 0) {
                    listarecuperada = listarecuperada->prox;
                }
                controlo++;
                ajogar = listarecuperada->jogador;
                tabuleiro = listarecuperada->tabuleiro;
                posicao = listarecuperada->posicao;
                lista = adiciona(lista, ajogar, tabuleiro, posicao);
                ajogar = jogada(tab, tabuleiro, posicao, ajogar);
                jogadasefetuadas++;
            } while (listarecuperada->prox != NULL);
            tabuleiro = posicao;
            for (int i = 0; i < N; ++i) {
                vencedor[i] = checkvencedor(tab, i + 1, N);
            }
            imprimetab(tab);
        } else {//limpar o ficheiro
            FILE *fb = fopen(FICHBIN, "w");
            listarecuperada = NULL;
            fclose(fb);
        }
    }
    if (mododejogo == 1) { //1jogador
        if (tabuleiro == 0) {
            ajogar = 'O';
            printf("Voce -> X\n");
            printf("Escolha o tabuleiro para comecar o jogo\n");
            do {
                printf("->");
                scanf("%d", &tabuleiro);
            } while (tabuleiro < 1 || tabuleiro > 9);
        }
        do {
            if (ajogar == 'O') {
                do {
                    posicao = initRandom();
                    if (tab[tabuleiro - 1][posicao - 1] != '-') {
                        posicao = 0;
                    }
                } while (posicao < 1 || posicao > 9);

                lista = adiciona(lista, ajogar, tabuleiro, posicao);
                ajogar = jogada(tab, tabuleiro, posicao, ajogar);
                jogadasefetuadas++;
                vencedor[tabuleiro - 1] = checkvencedor(tab, tabuleiro, N);
                imprimetab(tab);
                ovencedor = vencedordojogo(vencedor, N);
                tabuleiro = posicao;

            }
            do {
                if (vencedor[tabuleiro - 1] != ' ') {
                    tabuleiro += 1;
                }
                if (tabuleiro > 9) {
                    tabuleiro = 1;
                }
            } while (vencedor[tabuleiro - 1] != ' ' && ovencedor == ' ');
            if (ovencedor == ' ') {
                if (jogadasefetuadas > 0) {
                    mostrardecisao(lista, jogadasefetuadas);
                }
                posicao = posicaoajogar(tab, mododejogo, tabuleiro, ajogar);
                lista = adiciona(lista, ajogar, tabuleiro, posicao);
                ajogar = jogada(tab, tabuleiro, posicao, ajogar);
                jogadasefetuadas++;
                vencedor[tabuleiro - 1] = checkvencedor(tab, tabuleiro, N);
                ovencedor = vencedordojogo(vencedor, N);
                tabuleiro = posicao;
                do {
                    if (vencedor[tabuleiro - 1] != ' ') {
                        tabuleiro += 1;
                    }
                    if (tabuleiro > 9) {
                        tabuleiro = 1;
                    }
                } while (vencedor[tabuleiro - 1] != ' ' && ovencedor == ' ');
            }
        } while (ovencedor == ' ');
    } else {//2jogadores
        if (tabuleiro == 0) {
            printf("jogador %c, em que tabuleiro gostaria de jogar?\n", ajogar);
            ajogar = 'O';
            do {
                printf("->");
                scanf("%d", &tabuleiro);
            } while (tabuleiro < 1 || tabuleiro > 9);
        }
        do {
            do {
                if (vencedor[tabuleiro - 1] != ' ') {
                    tabuleiro += 1;
                }
                if (tabuleiro > 9) {
                    tabuleiro = 1;
                }
            } while (vencedor[tabuleiro - 1] != ' ');
            if (jogadasefetuadas > 0) {
                mostrardecisao(lista, jogadasefetuadas);
            }
            posicao = posicaoajogar(tab, mododejogo, tabuleiro, ajogar);
            lista = adiciona(lista, ajogar, tabuleiro, posicao);
            ajogar = jogada(tab, tabuleiro, posicao, ajogar);
            jogadasefetuadas++;
            vencedor[tabuleiro - 1] = checkvencedor(tab, tabuleiro, N);
            imprimetab(tab);
            ovencedor = vencedordojogo(vencedor, N);
            tabuleiro = posicao;
        } while (ovencedor == ' ');
    }
    if (ovencedor != 'E') {
        printf("O jogador %c venceu o jogo\n", ovencedor);
    } else {
        printf("O jogo terminou empatado\n");
    }
    FILE *fb = fopen(FICHBIN, "w");
    listarecuperada = NULL;
    char nomefch[64], fichtxt[69];
    printf("\nIndique o nome do ficheiro para guardar os detalhes do jogo\n");
    printf("->");
    scanf(" %s\n", &nomefch);
    sprintf(fichtxt, "%s.txt", nomefch);
    FILE *f = fopen(fichtxt, "w");
    if (f == NULL) {
        printf("Nao foi possivel criar o ficheiro\n");
        exit(-1);
    }
    escrevefich(f, lista);
    fclose(fb);
    fclose(f);
    return 0;
}
