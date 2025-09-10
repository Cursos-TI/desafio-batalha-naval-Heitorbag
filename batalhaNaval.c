#include <stdio.h>

int main() {
    
    // Representar o tabuleiro
    int tabuleiro[10][10];
    int i, j;

    // Inicializar todas as posições com 0
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Declarar e inicializar os navios
    int navioHorizontal[3] = {3, 3, 3}; 
    int navioVertical[3]   = {3, 3, 3};

    int h_linha = 5, h_coluna = 1; 
    int v_linha = 0, v_coluna = 7; 

    // Validar e posicionar o navio horizontal
    if(h_coluna + 3 <= 10) {
        for(j = 0; j < 3; j++) {
            tabuleiro[h_linha][h_coluna + j] = navioHorizontal[j];
        }
    }

    // Validar e posicionar o navio vertical
    if(v_linha + 3 <= 10) {
        for(i = 0; i < 3; i++) {
            if(tabuleiro[v_linha + i][v_coluna] == 0) { 
                tabuleiro[v_linha + i][v_coluna] = navioVertical[i];
            }
        }
    }

    // Navios diagonais
    int navioDiagonal1[3] = {3, 3, 3};
    int navioDiagonal2[3] = {3, 3, 3}; 

    int d1_linha = 2, d1_coluna = 2; // início da diagonal principal
    int d2_linha = 6, d2_coluna = 9; // início da diagonal secundária

     // Validar e posicionar o navio diagonal principal
    for(i = 0; i < 3; i++) {
        int linha = d1_linha + i;
        int coluna = d1_coluna + i;
        if(linha < 10 && coluna < 10 && tabuleiro[linha][coluna] == 0) {
            tabuleiro[linha][coluna] = navioDiagonal1[i];
        }
    }

    // Validar e posicionar o navio diagonal secundária
    for(i = 0; i < 3; i++) {
        int linha = d2_linha + i;
        int coluna = d2_coluna - i;
        if(linha < 10 && coluna >= 0 && tabuleiro[linha][coluna] == 0) {
            tabuleiro[linha][coluna] = navioDiagonal2[i];
        }
    }

    // Exibir o tabuleiro
    printf("Tabuleiro (0 = agua, 3 = navio):\n\n");
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
