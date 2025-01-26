#include "batalha_naval.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// Função utilitária para gerar uma posição aleatória
void gerar_posicao_aleatoria(int *x, int *y, int *horizontal) {
    *x = rand() % TAMANHO_TABULEIRO;
    *y = rand() % TAMANHO_TABULEIRO;
    *horizontal = rand() % 2;
}

// Função utilitária para verificar se todas as partes de um navio foram atingidas
int navio_atingido(Tabuleiro *tabuleiro, char simbolo) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro->tabuleiro[i][j] == simbolo) {
                return 0; // Ainda há partes do navio não atingidas
            }
        }
    }
    return 1; // Todas as partes do navio foram atingidas
}

// Função utilitária para verificar se todos os navios foram destruídos
int todos_navios_destruidos(Tabuleiro *tabuleiro) {
    for (int i = 0; i < NUM_NAVIOS; i++) {
        if (!navio_atingido(tabuleiro, tabuleiro->navios[i].simbolo)) {
            return 0; // Ainda há navios não destruídos
        }
    }
    return 1; // Todos os navios foram destruídos
}