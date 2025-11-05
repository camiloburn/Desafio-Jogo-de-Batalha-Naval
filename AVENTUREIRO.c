#include <stdio.h>

#define N 10
#define AGUA 0
#define NAVIO 3

void imprimir_tabuleiro(int tab[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%d ", tab[i][j]);
        printf("\n");
    }
}

int dentro(int l, int c) { return l >= 0 && l < N && c >= 0 && c < N; }

int checar_sobreposicao(int tab[N][N], int posicoes[][2], int qtd) {
    for (int k = 0; k < qtd; k++) {
        int l = posicoes[k][0], c = posicoes[k][1];
        if (!dentro(l, c)) return 0;
        if (tab[l][c] != AGUA) return 0;
    }
    return 1;
}

void aplicar_posicoes(int tab[N][N], int posicoes[][2], int qtd) {
    for (int k = 0; k < qtd; k++) {
        tab[posicoes[k][0]][posicoes[k][1]] = NAVIO;
    }
}

int main() {
    int tab[N][N];
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) tab[i][j]=AGUA;

    int tamanho = 3;

    int nav1[3][2] = {{1,1},{1,2},{1,3}};
    int nav2[3][2] = {{4,5},{5,5},{6,5}};
    int nav3[3][2] = {{7,0},{8,1},{9,2}};
    int nav4[3][2] = {{2,7},{1,8},{0,9}};

    if (checar_sobreposicao(tab, nav1, tamanho)) aplicar_posicoes(tab, nav1, tamanho);
    else printf("Navio horizontal 1 nao coube.\n");

    if (checar_sobreposicao(tab, nav2, tamanho)) aplicar_posicoes(tab, nav2, tamanho);
    else printf("Navio vertical 2 nao coube.\n");

    if (checar_sobreposicao(tab, nav3, tamanho)) aplicar_posicoes(tab, nav3, tamanho);
    else printf("Navio diagonal 3 nao coube.\n");

    if (checar_sobreposicao(tab, nav4, tamanho)) aplicar_posicoes(tab, nav4, tamanho);
    else printf("Navio diagonal 4 nao coube.\n");

    printf("Tabuleiro (0 = agua, 3 = navio):\n");
    imprimir_tabuleiro(tab);

    return 0;
}
