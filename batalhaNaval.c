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
    int navioDiagonal1[3]  = {3, 3, 3};
    int navioDiagonal2[3]  = {3, 3, 3};

    int h_linha = 5, h_coluna = 1;
    int v_linha = 0, v_coluna = 7;
    int d1_linha = 2, d1_coluna = 2;
    int d2_linha = 6, d2_coluna = 9;

    // Validar e posicionar o navio horizontal
    if(h_coluna + 3 <= 10) {
        for(j = 0; j < 3; j++)
            tabuleiro[h_linha][h_coluna + j] = navioHorizontal[j];
    }

    // Validar e posicionar o navio vertical
    if(v_linha + 3 <= 10) {
        for(i = 0; i < 3; i++)
            if(tabuleiro[v_linha + i][v_coluna] == 0)
                tabuleiro[v_linha + i][v_coluna] = navioVertical[i];
    }

    // Validar e posicionar o navio diagonal principal
    for(i = 0; i < 3; i++) {
        int linha = d1_linha + i;
        int coluna = d1_coluna + i;
        if(linha < 10 && coluna < 10 && tabuleiro[linha][coluna] == 0)
            tabuleiro[linha][coluna] = navioDiagonal1[i];
    }

    // Validar e posicionar o navio diagonal secundária
    for(i = 0; i < 3; i++) {
        int linha = d2_linha + i;
        int coluna = d2_coluna - i;
        if(linha < 10 && coluna >= 0 && tabuleiro[linha][coluna] == 0)
            tabuleiro[linha][coluna] = navioDiagonal2[i];
    }

    // Criar matrizes de habilidades (5x5)
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // Construir habilidade Cone
    for(i = 0; i < 5; i++) {
        for(j = 2-i; j <= 2+i; j++) {
            if(j >= 0 && j < 5)
                cone[i][j] = 1;
        }
    }

    // Construir habilidade Cruz
    for(i = 0; i < 5; i++) {
        cruz[2][i] = 1; 
        cruz[i][2] = 1;
    }

    // Construir habilidade Octaedro
    octaedro[0][2] = 1;
    octaedro[1][1] = octaedro[1][2] = octaedro[1][3] = 1;
    octaedro[2][0] = octaedro[2][1] = octaedro[2][2] = octaedro[2][3] = octaedro[2][4] = 1;
    octaedro[3][1] = octaedro[3][2] = octaedro[3][3] = 1;
    octaedro[4][2] = 1;

    // Integrar habilidades ao tabuleiro
    int orig_cone_linha = 0, orig_cone_coluna = 5;
    int orig_cruz_linha = 7, orig_cruz_coluna = 2;
    int orig_octa_linha = 4, orig_octa_coluna = 7;

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            // Cone
            int linha = orig_cone_linha + i - 2;
            int coluna = orig_cone_coluna + j - 2;
            if(linha >=0 && linha < 10 && coluna >=0 && coluna < 10 && cone[i][j] == 1)
                tabuleiro[linha][coluna] = 5;

            // Cruz
            linha = orig_cruz_linha + i - 2;
            coluna = orig_cruz_coluna + j - 2;
            if(linha >=0 && linha < 10 && coluna >=0 && coluna < 10 && cruz[i][j] == 1)
                tabuleiro[linha][coluna] = 5;

            // Octaedro
            linha = orig_octa_linha + i - 2;
            coluna = orig_octa_coluna + j - 2;
            if(linha >=0 && linha < 10 && coluna >=0 && coluna < 10 && octaedro[i][j] == 1)
                tabuleiro[linha][coluna] = 5;
        }
    }

    // Exibir o tabuleiro
    printf("Tabuleiro (0 = agua, 3 = navio, 5 = area de habilidade):\n\n");
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
