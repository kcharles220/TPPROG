//Trabalho Prático Programação 2021/2022
//Realizado por:
//Carlos Manuel Pascoal Pinto 2021155627

#include "lista.h"
#include "stdlib.h"
#include "stdio.h"

#define FICHBIN "jogo.bin"

pjog novajog(char jogador, int tabuleiro, int posicao) {
    pjog p = malloc(sizeof(jog));
    if ((malloc(sizeof(jog))) == NULL) {
        printf("Erro a alocar memória");
        return NULL;
    }
    p->jogador = jogador;
    p->tabuleiro = tabuleiro;
    p->posicao = posicao;
    p->prox = NULL;
    return p;
}

pjog adiciona(pjog lista, char jogador, int tabuleiro, int posicao) { //adiciona a nova jogada a lista
    pjog aux;
    pjog p = novajog(jogador, tabuleiro, posicao);
    if (lista == NULL) {
        return p;
    }
    aux = lista;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = p;
    guarda_lista(FICHBIN, lista);
    return lista;
}


void mostra_lista(pjog lista, int jogadasefetuadas, int njogadas) {
    pjog aux = lista;
    int jogadas = jogadasefetuadas - njogadas;
    for (int i = 0; i < jogadas; ++i) {
        aux = aux->prox;
    }
    while (aux != NULL) {
        printf("\nO jogador %c jogou na posicao %d do tabuleiro %d", aux->jogador, aux->posicao, aux->tabuleiro);
        aux = aux->prox;
    }
    printf("\n");
}

void mostrardecisao(pjog lista, int jogadasefetuadas) {//ver as ultimas x jogadas (ate 10)
    int njogadas = 0;
    printf("Gostaria de ver ate 10 ultimas jogadas realizadas?\nSe sim digite o numero de jogadas que deseja ver\nSe nao digite 0\n");
    do {
        printf("->");
        scanf("%d", &njogadas);
    } while (njogadas < 0 || njogadas > jogadasefetuadas || njogadas > 10);
    if (njogadas != 0) {
        printf("-------------------HISTORICO-------------------");
        mostra_lista(lista, jogadasefetuadas, njogadas);
        printf("-----------------------------------------------\n");
    }
}

pjog recuperarjogo(char *fich, int *tam) {//recupera o jogo que esta guardado no ficheiro jogo.bin e retorna a lista modificada
    FILE *f;
    pjog pnovo, lista = NULL, aux2;
    jog aux;
    if ((f = fopen(fich, "rb")) == NULL) {
        printf("Erro ao abrir ficheiro\n");
        return NULL;
    }
    while (fread(&aux, sizeof(jog), 1, f) == 1) {
        aux.prox = NULL;
        pnovo = malloc(sizeof(jog));
        if (pnovo == NULL) {
            printf("ERRO");
            fclose(f);
            return NULL;
        }
        *pnovo = aux;
        if (lista == NULL) {
            lista = pnovo;
        } else {
            aux2 = lista;
            while (aux2->prox != NULL) {
                aux2 = aux2->prox;
            }
            aux2->prox = pnovo;
        }
        (*tam)++;
    }
    fclose(f);
    return lista;
}

int isvazio(char *fich) { //verifica se o ficheiro jogo.bin esta vazio, retorna 1 se sim ,0 caso contrario
    FILE *f;
    int vazio = 0, tam;
    f = fopen(fich, "rb");
    if (NULL != f) {
        fseek(f, 0, SEEK_END);
        tam = ftell(f);
        if (tam == 0) {
            vazio = 1;
        }
    }
    return vazio;
}

void guarda_lista(char *fich, struct jogadas *lista) {
    FILE *f;
    f = fopen(fich, "wb");
    pjog aux = lista;
    if (f == NULL) {
        printf("ERRO ao armazenar lista\n");
        return;
    }
    while (aux != NULL) {
        fwrite(aux, sizeof(jog), 1, f);
        aux = aux->prox;
    }
    fclose(f);
}

void escrevefich(FILE *f, pjog lista) { //escreve informacoes sobre todas as jogadas no ficheiro
    pjog aux = lista;

    while (aux != NULL) {
        fprintf(f, "O jogador %c jogou na posicao %d do tabuleiro %d\n", aux->jogador, aux->posicao, aux->tabuleiro);
        aux = aux->prox;
    }

}