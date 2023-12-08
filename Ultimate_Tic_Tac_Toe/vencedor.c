//Trabalho Prático Programação 2021/2022
//Realizado por:
//Carlos Manuel Pascoal Pinto 2021155627

#include "math.h"

#define N 9

char checkvencedor(char **tabela, int tabuleiro, int c) {//verifica se alguém venceu o tabuleiro da ultima jogada, se sim guarda-o no array na posicao correspondente ao tabuleiro ganho (empates incluidos)
    tabuleiro += -1;
    int cont = 0;
    char vencedor = ' ';
    do {
        if (tabela[tabuleiro][cont] == 'X' || tabela[tabuleiro][cont] == 'O') {
            if (tabela[tabuleiro][cont] == tabela[tabuleiro][cont + 1] &&
                tabela[tabuleiro][cont] == tabela[tabuleiro][cont + 2]) {
                vencedor = tabela[tabuleiro][cont];
            }
        }
        cont += 3;
    } while (cont <= c && vencedor == ' ');
    cont = 0;
    if (vencedor == ' ') {
        do {
            if (tabela[tabuleiro][cont] == 'X' || tabela[tabuleiro][cont] == 'O') {
                if (tabela[tabuleiro][cont] == tabela[tabuleiro][cont + 3] &&
                    tabela[tabuleiro][cont] == tabela[tabuleiro][cont + 6]) {
                    vencedor = tabela[tabuleiro][cont];
                }
            }
            cont += 1;

        } while (cont < sqrt(c) && vencedor == ' ');
    }
    cont = 0;
    if (vencedor == ' ') {
        if (tabela[tabuleiro][cont] == 'X' || tabela[tabuleiro][cont] == 'O') {
            if (tabela[tabuleiro][cont] == tabela[tabuleiro][cont + 4] &&
                tabela[tabuleiro][cont] == tabela[tabuleiro][cont + 8]) {
                vencedor = tabela[tabuleiro][cont];
            }
        }
    }
    if (vencedor == ' ') {
        cont = 2;
        if (tabela[tabuleiro][cont] == 'X' || tabela[tabuleiro][cont] == 'O') {
            if (tabela[tabuleiro][cont] == tabela[tabuleiro][cont + 2] &&
                tabela[tabuleiro][cont] == tabela[tabuleiro][cont + 4]) {
                vencedor = tabela[tabuleiro][cont];
            }
        }
    }
    if (vencedor == ' ') {
        for (int i = 0; i < c; ++i) {
            if (tabela[tabuleiro][i] == '-') {
                vencedor = ' ';
                i = c;
            } else {
                vencedor = 'E';
            }
        }
    }
    if (vencedor == 'O') {
        for (int i = 0; i < c; ++i) {
            tabela[tabuleiro][i] = vencedor;
        }
    }
    if (vencedor == 'X') {
        for (int i = 0; i < c; ++i) {
            tabela[tabuleiro][i] = vencedor;
        }
    }
    if (vencedor == 'E') {
        for (int i = 0; i < c; ++i) {
            tabela[tabuleiro][i] = vencedor;
        }
    }

    return vencedor;
}

char vencedordojogo(char *vencedores, int c) { //verifica se alguem venceu(ou empatou) o jogo a partir dos vencedores de cada tabuleiro
    char vencedor = ' ';
    int n = c;
    c = sqrt(c);
    int cont = 0;
    do {
        if (vencedores[cont] == 'X' || vencedores[cont] == 'O') {
            if (vencedores[cont] == vencedores[cont + 1] &&
                vencedores[cont] == vencedores[cont + 2]) {
                vencedor = vencedores[cont];
            }
        }
        cont += 3;
    } while (cont <= n && vencedor == ' ');
    cont = 0;
    if (vencedor == ' ') {
        do {
            if (vencedores[cont] == 'X' || vencedores[cont] == 'O') {
                if (vencedores[cont] == vencedores[cont + 3] &&
                    vencedores[cont] == vencedores[cont + 6]) {
                    vencedor = vencedores[cont];
                }
            }
            cont += 1;
        } while (cont <= c && vencedor == ' ');
    }

    cont = 0;
    if (vencedor == ' ') {
        if (vencedores[cont] == 'X' || vencedores[cont] == 'O') {
            if (vencedores[cont] == vencedores[cont + 4] &&
                vencedores[cont] == vencedores[cont + 8]) {
                vencedor = vencedores[cont];
            }
        }
    }
    if (vencedor == ' ') {
        cont = 2;
        if (vencedores[cont] == 'X' || vencedores[cont] == 'O') {
            if (vencedores[cont] == vencedores[cont + 2] &&
                vencedores[cont] == vencedores[cont + 4]) {
                vencedor = vencedores[cont];
            }
        }
    }
    if (vencedor == ' ') {
        for (int i = 0; i < n; ++i) {
            if (vencedores[i] == ' ') {
                vencedor = ' ';
                i = n;
            } else {
                vencedor = 'E';
            }
        }
    }

    return vencedor;
}