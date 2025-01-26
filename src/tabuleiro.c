#include "batalha_naval.h"
#include <stdio.h>
#include <stdlib.h>

// Definição das constantes
#define TAMANHO_TABULEIRO 10
#define NUM_NAVIOS 5

// Estrutura para representar um navio
typedef struct {
    int tamanho;
    char simbolo;
} Navio;

// Estrutura para representar o tabuleiro
typedef struct {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    Navio navios[NUM_NAVIOS];
} Tabuleiro;

// Função para inicializar o tabuleiro
void inicializar_tabuleiro(Tabuleiro *tabuleiro) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro->tabuleiro[i][j] = '~';
        }
    }
}

// Função para posicionar um navio no tabuleiro
void posicionar_navio(Tabuleiro *tabuleiro, int x, int y, int tamanho, char simbolo, int horizontal) {
    if (horizontal) {
        for (int i = 0; i < tamanho; i++) {
            if (x + i < TAMANHO_TABULEIRO) {
                tabuleiro->tabuleiro[y][x + i] = simbolo;
            }
        }
    } else {
        for (int i = 0; i < tamanho; i++) {
            if (y + i < TAMANHO_TABULEIRO) {
                tabuleiro->tabuleiro[y + i][x] = simbolo;
            }
        }
    }
}

// Função para verificar um tiro no tabuleiro
char verificar_tiro(Tabuleiro *tabuleiro, int x, int y) {
    if (tabuleiro->tabuleiro[y][x] != '~') {
        char simbolo = tabuleiro->tabuleiro[y][x];
        tabuleiro->tabuleiro[y][x] = 'X';
        return simbolo;
    } else {
        tabuleiro->tabuleiro[y][x] = 'O';
        return '~';
    }
}

// Função para imprimir o tabuleiro
void imprimir_tabuleiro(Tabuleiro *tabuleiro) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro->tabuleiro[i][j]);
        }
        printf("\n");
    }
}