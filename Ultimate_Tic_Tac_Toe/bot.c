//Trabalho Prático Programação 2021/2022
//Realizado por:
//Carlos Manuel Pascoal Pinto 2021155627

#include "time.h"
#include "stdlib.h"
#include "bot.h"

int intUniformRnd(int a, int b) {//numero random entre b e a
    return a + rand() % (b - a + 1);
}

int initRandom() {//retorna uma posicao random
    int posicao = 0;
    srand(time(NULL));
    posicao = intUniformRnd(1, 9);
    return posicao;
}