#include <stdio.h>


int main() {
    //tabuleiro 10x10 com 0 (água)
    int tabuleiro[10][10];
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio 1 - horizontal (3 espaços)
    int linha1 = 3;
    int coluna1 = 2;

    tabuleiro[linha1][coluna1] = 3;
    tabuleiro[linha1][coluna1 + 1] = 3;
    tabuleiro[linha1][coluna1 + 2] = 3;

    // Navio 2 - vertical (3 espaços)
    int linha2 = 6;
    int coluna2 = 7;

    tabuleiro[linha2][coluna2] = 3;
    tabuleiro[linha2 + 1][coluna2] = 3;
    tabuleiro[linha2 + 2][coluna2] = 3;

    // Mostrando o tabuleiro
    printf("TABULEIRO BATALHA NAVAL\n\n");

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
