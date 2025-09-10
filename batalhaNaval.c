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
    int navioHorizontal[3] = {3, 3, 3}; // navio horizontal
    int navioVertical[3]   = {3, 3, 3}; // navio vertical

    // 3) Definir coordenadas iniciais dos navios (entrada direta no código)
    int h_linha = 4;   
    int h_coluna = 2;  

    int v_linha = 0;   
    int v_coluna = 7;  

    // Validar e posicionar o navio horizontal
    if(h_coluna + 3 <= 10) { 
        for(j = 0; j < 3; j++) {
            tabuleiro[h_linha][h_coluna + j] = navioHorizontal[j];
        }
    } else {
        printf("Erro: navio horizontal nao cabe no tabuleiro.\n");
    }

    // Validar e posicionar o navio vertical
    if(v_linha + 3 <= 10) { 
        for(i = 0; i < 3; i++) {
            if(tabuleiro[v_linha + i][v_coluna] == 0) { 
                tabuleiro[v_linha + i][v_coluna] = navioVertical[i];
            } else {
                printf("Aviso: navio vertical nao pode sobrepor outro navio.\n");
            }
        }
    } else {
        printf("Erro: navio vertical nao cabe no tabuleiro.\n");
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
