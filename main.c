#include <stdio.h>
#include <stdlib.h>

void preencherMatriz(char ***matriz) {
    char letras[52] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z'};

    *matriz = malloc(52 * sizeof(char *));
    for (int i = 0; i < 52; i++) {
        (*matriz)[i] = malloc(52 * sizeof(char));
    }

    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            (*matriz)[i][j] = letras[(i + j) % 52];
        }
    }
}

void preencherVetor(char **vet) {
    char letras[52] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z'};

    *vet = malloc(52 * sizeof(char));

    for (int i = 0; i < 52; i++) {
        (*vet)[i] = letras[i];
    }
}

void limpaMemoria(char **vet, char ***matriz) {
    for (int i = 0; i < 52; i++) {
        free((*matriz)[i]);
    }
    free(*matriz);
    free(*vet);

    // Defina os ponteiros para NULL após liberar a memória
    *matriz = NULL;
    *vet = NULL;
}

int main() {
    char **matriz = NULL;
    char *vet = NULL;

    preencherMatriz(&matriz);
    preencherVetor(&vet);

    for (int i = 0; i < 52; i++) {
        printf("%c ", vet[i]);
    }
    printf("\n\n");

    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
    limpaMemoria(&vet, &matriz);
    

    /*Fiz as criações dos vetores e matrizes para pegarmos os caracteres
    Estou pensando em fazer assim
    
    Por exemplo se a entrada da pessoa for "Cada Canto" e "Aventura" tem que organizar esse espaço para codificar
    
    Cada Canto
    Aven turaA
    
    ai temos para a primeira letra o C e o A, nisso ele vai no vetor e pega a posição de C e depois de A
    
    a posição de C é [4] e de A é [0]
    
    Ai ele vai la na matriz e pega a letra na posição [4][0] que neste caso é C
    
    ai na segunda, letra "a" e "v" , nisso ele vai no vetor e pega a posição de a e depois de v
    
    a posição de "a" é [1] e de v é [43]
    
    Ai ele vai la na matriz e pega a letra na posição [1][43] que neste caso é W
    
    e assim por diante ate acabar toda a String e depois imprime a codificada
    */
    
    
    return 0;
}