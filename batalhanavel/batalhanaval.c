#include <stdio.h>
#include <stdlib.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // 1. Inicializa o tabuleiro com água (0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Coloca os navios (valor 3)
    tabuleiro[1][2] = 3;
    tabuleiro[1][3] = 3;
    tabuleiro[1][4] = 3;

    tabuleiro[4][5] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[6][5] = 3;

    tabuleiro[7][1] = 3;
    tabuleiro[8][2] = 3;
    tabuleiro[9][3] = 3;

    tabuleiro[0][9] = 3;
    tabuleiro[1][8] = 3;
    tabuleiro[2][7] = 3;

    // 3. Cria matriz de habilidade CONE (5x5)
    int cone[5][5];
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // 4. Cria matriz de habilidade CRUZ (5x5)
    int cruz[5][5];
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // 5. Cria matriz de habilidade OCTAEDRO (5x5)
    int octaedro[5][5];
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // 6. Aplica o cone no tabuleiro (origem: 2,2)
    int origemLinha = 2;
    int origemColuna = 2;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int linha = origemLinha - 2 + i;
            int coluna = origemColuna - 2 + j;

            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 &&
                cone[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                tabuleiro[linha][coluna] = 5;
            }
        }
    }

    // 7. Aplica a cruz no tabuleiro (origem: 6,6)
    origemLinha = 6;
    origemColuna = 6;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int linha = origemLinha - 2 + i;
            int coluna = origemColuna - 2 + j;

            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 &&
                cruz[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                tabuleiro[linha][coluna] = 5;
            }
        }
    }

    // 8. Aplica o octaedro no tabuleiro (origem: 8,8)
    origemLinha = 8;
    origemColuna = 8;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            int linha = origemLinha - 2 + i;
            int coluna = origemColuna - 2 + j;

            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 &&
                octaedro[i][j] == 1 && tabuleiro[linha][coluna] == 0) {
                tabuleiro[linha][coluna] = 5;
            }
        }
    }

    // 9. Mostra o tabuleiro
    printf("TABULEIRO FINAL\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("~ "); // água
            } else if (tabuleiro[i][j] == 3) {
                printf("N "); // navio
            } else if (tabuleiro[i][j] == 5) {
                printf("* "); // habilidade
            }
        }
        printf("\n");
    }

    return 0;
}


// eu amo minha vida
