
#include <stdio.h>
#include <stdlib.h>

#define N 10
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5
#define M 5

void imprimir_tabuleiro(int tab[N][N]) {
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++) printf("%d ", tab[i][j]);
        printf("\n");
    }
}

int dentro(int l, int c) { return l >= 0 && l < N && c >= 0 && c < N; }

void construi_cone(int cone[M][M]) {
    for (int i=0;i<M;i++){
        for (int j=0;j<M;j++){
            int centro = M/2;
            int largura = i;
            if (j >= centro - largura && j <= centro + largura) cone[i][j] = 1;
            else cone[i][j] = 0;
        }
    }
}

void construi_cruz(int cruz[M][M]) {
    int centro = M/2;
    for (int i=0;i<M;i++) for (int j=0;j<M;j++)
        cruz[i][j] = (i==centro || j==centro) ? 1 : 0;
}

void construi_octaedro(int oct[M][M]) {
    int centro = M/2;
    for (int i=0;i<M;i++){
        int distancia = centro - (i < centro ? i : (M-1-i));
        for (int j=0;j<M;j++){
            int raio = centro - distancia;
            if (abs(j - centro) <= raio) oct[i][j] = 1;
            else oct[i][j] = 0;
        }
    }
}

void sobrepoe_habilidade(int tab[N][N], int habilidade[M][M], int orig_l, int orig_c) {
    int meio = M/2;
    for (int i=0;i<M;i++){
        for (int j=0;j<M;j++){
            if (habilidade[i][j] == 1) {
                int l = orig_l + (i - meio);
                int c = orig_c + (j - meio);
                if (dentro(l,c)) {
                    if (tab[l][c] == AGUA) tab[l][c] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tab[N][N];
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) tab[i][j]=AGUA;

    int nav1[3][2] = {{1,1},{1,2},{1,3}};
    int nav2[3][2] = {{4,5},{5,5},{6,5}};
    int nav3[3][2] = {{7,0},{8,1},{9,2}};
    int nav4[3][2] = {{2,7},{1,8},{0,9}};

    for (int k=0;k<3;k++){
        tab[nav1[k][0]][nav1[k][1]] = NAVIO;
        tab[nav2[k][0]][nav2[k][1]] = NAVIO;
        tab[nav3[k][0]][nav3[k][1]] = NAVIO;
        tab[nav4[k][0]][nav4[k][1]] = NAVIO;
    }

    int cone[M][M], cruz[M][M], octa[M][M];
    construi_cone(cone);
    construi_cruz(cruz);
    construi_octaedro(octa);

    int orig_cone_l = 1, orig_cone_c = 6;
    int orig_cruz_l = 5, orig_cruz_c = 2;
    int orig_octa_l = 7, orig_octa_c = 7;

    sobrepoe_habilidade(tab, cone, orig_cone_l, orig_cone_c);
    sobrepoe_habilidade(tab, cruz, orig_cruz_l, orig_cruz_c);
    sobrepoe_habilidade(tab, octa, orig_octa_l, orig_octa_c);

    printf("Tabuleiro final (0=agua,3=navio,5=area habilidade):\n");
    imprimir_tabuleiro(tab);

    printf("\nMatriz Cone (1=afetado):\n");
    for (int i=0;i<M;i++){ for (int j=0;j<M;j++) printf("%d ", cone[i][j]); printf("\n"); }

    printf("\nMatriz Cruz (1=afetado):\n");
    for (int i=0;i<M;i++){ for (int j=0;j<M;j++) printf("%d ", cruz[i][j]); printf("\n"); }

    printf("\nMatriz Octaedro (1=afetado):\n");
    for (int i=0;i<M;i++){ for (int j=0;j<M;j++) printf("%d ", octa[i][j]); printf("\n"); }

    return 0;
}
