#include "batalha_naval.h"
#include <stdlib.h>
#include <time.h>

void inicializar_tabuleiro(Tabuleiro *tabuleiro) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro->tabuleiro[i][j] = '~';
        }
    }
}

void imprimir_tabuleiro(const Tabuleiro *tabuleiro) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro->tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void colocar_navio(Tabuleiro *tabuleiro, int x, int y) {
    if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO) {
        tabuleiro->tabuleiro[x][y] = 'N';
    }
}

bool atirar(Tabuleiro *tabuleiro, int x, int y) {
    if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO) {
        if (tabuleiro->tabuleiro[x][y] == 'N') {
            tabuleiro->tabuleiro[x][y] = 'X';
            return true;
        } else {
            tabuleiro->tabuleiro[x][y] = 'O';
            return false;
        }
    }
    return false;
}
