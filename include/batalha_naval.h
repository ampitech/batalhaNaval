#ifndef BATALHA_NAVAL_H
#define BATALHA_NAVAL_H

#define TAMANHO_TABULEIRO 10

typedef struct {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
} Tabuleiro;

void inicializar_tabuleiro(Tabuleiro *tabuleiro);
void imprimir_tabuleiro(const Tabuleiro *tabuleiro);
void colocar_navio(Tabuleiro *tabuleiro, int x, int y);
bool atirar(Tabuleiro *tabuleiro, int x, int y);

#endif // BATALHA_NAVAL_H
