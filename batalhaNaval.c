#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int linhas = 10, colunas = 10;
    int tabuleiro[linhas][colunas];
    int navio = 3;
    int tamanho = 3;

    // Inicializa tabuleiro full água == 0
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    srand(time(0));

    // ---- navio horizontal ----
    int colocado = 0; //começa assumindo que não foi colocado o navio
    while (!colocado) {
        int x = rand() % linhas;
        int y = rand() % (colunas - tamanho); // garante que não passa da borda

        // Verifica se espaço está livre
        int livre = 1; //começa assumindo que está livre a posição
        for (int k = 0; k < tamanho; k++) { // percorre 3 posições
            if (tabuleiro[x][y + k] != 0) { // verifica se as 3 posições estão diferentes de 0, se alguma não for zero, assume que não está livre, livre = 0
                livre = 0;
            }
        } 
        //no caso de livre 0, o loop se reinicia
        if (livre) { //se estiver livre ele adiciona o navio
            for (int k = 0; k < tamanho; k++) {
                tabuleiro[x][y + k] = navio;
            }
            colocado = 1; //informa que foi colocado para sair do loop de while
        }
    }

    // ---- navio vertical ----
    colocado = 0;
    while (!colocado) {
        int x = rand() % (linhas - tamanho);
        int y = rand() % colunas;

        int livre = 1;
        for (int k = 0; k < tamanho; k++) {
            if (tabuleiro[x + k][y] != 0) {
                livre = 0;
            }
        }

        if (livre) {
            for (int k = 0; k < tamanho; k++) {
                tabuleiro[x + k][y] = navio;
            }
            colocado = 1;
        }
    }

    // ---- navio diagonal 1 ----
    colocado = 0;
    while (!colocado) {
        int x = rand() % (linhas - tamanho);
        int y = rand() % (colunas - tamanho);

        int livre = 1;
        for (int k = 0; k < tamanho; k++) {
            if (tabuleiro[x + k][y + k] != 0) {
                livre = 0;
            }
        }

        if (livre) {
            for (int k = 0; k < tamanho; k++) {
                tabuleiro[x + k][y + k] = navio;
            }
            colocado = 1;
        }
    }

    // ---- navio diagonal 2 ----
    colocado = 0;
    while (!colocado) {
        int x = rand() % (linhas - tamanho);
        int y = rand() % (colunas - tamanho);

        int livre = 1;
        for (int k = 0; k < tamanho; k++) {
            if (tabuleiro[x + k][y + k] != 0) {
                livre = 0;
            }
        }

        if (livre) {
            for (int k = 0; k < tamanho; k++) {
                tabuleiro[x + k][y + k] = navio;
            }
            colocado = 1;
        }
    }

    // ---- Mostra tabuleiro ----
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
