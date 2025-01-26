#include <stdio.h>
#include "batalha_naval.h"

int main() {
    Tabuleiro tabuleiro;
    inicializar_tabuleiro(&tabuleiro);
    colocar_navio(&tabuleiro, 2, 2);
    colocar_navio(&tabuleiro, 5, 5);
    imprimir_tabuleiro(&tabuleiro);

    int x, y;
    while (1) {
        printf("Digite as coordenadas do tiro (x y): ");
        scanf("%d %d", &x, &y);
        if (atirar(&tabuleiro, x, y)) {
            printf("Acertou um navio!\n");
        } else {
            printf("Errou!\n");
        }
        imprimir_tabuleiro(&tabuleiro);
    }

    return 0;
}
