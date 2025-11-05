#include <stdio.h>

#define N 10
#define AGUA 0
#define NAVIO 3

void imprimir_tabuleiro(int tab[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

int dentro_do_tabuleiro(int linha, int coluna) {
    return linha >= 0 && linha < N && coluna >= 0 && coluna < N;
}

int valida_posicao_horizontal(int tab[N][N], int linha, int coluna_inicio, int tamanho) {
    for (int c = coluna_inicio; c < coluna_inicio + tamanho; c++) {
        if (!dentro_do_tabuleiro(linha, c)) return 0;
        if (tab[linha][c] != AGUA) return 0;
    }
    return 1;
}

int valida_posicao_vertical(int tab[N][N], int linha_inicio, int coluna, int tamanho) {
    for (int l = linha_inicio; l < linha_inicio + tamanho; l++) {
        if (!dentro_do_tabuleiro(l, coluna)) return 0;
        if (tab[l][coluna] != AGUA) return 0;
    }
    return 1;
}

void posiciona_horizontal(int tab[N][N], int linha, int coluna_inicio, int tamanho) {
    for (int c = coluna_inicio; c < coluna_inicio + tamanho; c++) tab[linha][c] = NAVIO;
}

void posiciona_vertical(int tab[N][N], int linha_inicio, int coluna, int tamanho) {
    for (int l = linha_inicio; l < linha_inicio + tamanho; l++) tab[l][coluna] = NAVIO;
}

int main() {
    int tab[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tab[i][j] = AGUA;

    int tamanho_navio = 3;
    int h_linha = 2, h_col_inicio = 1;
    int v_linha_inicio = 5, v_coluna = 7;

    if (valida_posicao_horizontal(tab, h_linha, h_col_inicio, tamanho_navio)) {
        posiciona_horizontal(tab, h_linha, h_col_inicio, tamanho_navio);
    } else {
        printf("Não foi possível posicionar o navio horizontal.\n");
    }

    if (valida_posicao_vertical(tab, v_linha_inicio, v_coluna, tamanho_navio)) {
        posiciona_vertical(tab, v_linha_inicio, v_coluna, tamanho_navio);
    } else {
        printf("Não foi possível posicionar o navio vertical.\n");
    }

    printf("Tabuleiro (0 = agua, 3 = navio):\n");
    imprimir_tabuleiro(tab);

    return 0;
}
