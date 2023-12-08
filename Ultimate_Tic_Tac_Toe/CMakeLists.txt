cmake_minimum_required(VERSION 3.21)
project(jogogalo C)

set(CMAKE_C_STANDARD 99)

add_executable(jogogalo main.c imprimetab.c vencedor.c bot.c lista.c jogo.c)
