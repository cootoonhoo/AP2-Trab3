#include <stdio.h>
#include <stdlib.h>

char ** GerarMatriz()
{
    char ** Matriz = (char **)malloc(52 * sizeof(char *));
    if(Matriz == NULL) return NULL;
    for(int i = 0; i < 52; i++)
    {
        Matriz[i] = (char *)malloc(52 * sizeof(char));
        if(Matriz[i] == NULL) return NULL;
    }
    return Matriz;
}

char * GerarString()
{
    char * string;
    string = (char *)malloc(500 * sizeof(char));
    if(string == NULL) return NULL;
    return string;
}

int stringLength(char * string)
{
    if(string[0] == '\0' ||  string[0] == '\n') return 0;
    return 1 + stringLength(string+1);
}

char * AjustarTamanhoString(char * string)
{
    int tam = stringLength(string);
    string = (char *)realloc(string, (tam + 1)*sizeof(char));
    
    string[tam] = '\0';
    return string;
}

void PreencherTabela(char **matriz) {
    char letras[52] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z'};
    int ContadorLetras = 0;
    for(int i = 0; i < 52; i++)
    {
        ContadorLetras = i;
        for(int j = 0; j < 52; j++)
        {
            if(ContadorLetras == 52)
                ContadorLetras = 0;
            matriz[i][j] = letras[ContadorLetras];
            ContadorLetras++;
        }
    }
}



void Erro(char msg[])
{
    system("cls");
    system("color 4F");
    printf("%s", msg);
    system("pause");
}

int main() {
    char **TabulaRasa = NULL;
    char * MsgAberta;
    char * PalavraChave;

    TabulaRasa = GerarMatriz();
    if(TabulaRasa == NULL)
    {
        Erro("Nao foi possivel alocar a matriz!\n");
        exit(-1);
    }

    MsgAberta = GerarString();
    if(MsgAberta == NULL)
    {
        Erro("Nao foi possivel alocar a MsgAberta!\n");
        exit(-1);
    }

    PalavraChave = GerarString();
    if(PalavraChave == NULL)
    {
        Erro("Nao foi possivel alocar a PalavraChave!\n");
        exit(-1);
    }

    PreencherTabela(TabulaRasa);

    printf("Digite a mensagem aberta:\n");
    fgets(MsgAberta , 500, stdin);
    fflush(stdin);
    AjustarTamanhoString(MsgAberta);

    printf("Digite a palavra chave:\n");
    fgets(PalavraChave , 500, stdin);
    fflush(stdin);
    AjustarTamanhoString(PalavraChave);



    // for (int i = 0; i < 52; i++) {
    //     for (int j = 0; j < 52; j++) {
    //         printf("%c ", TabulaRasa[i][j]);
    //     }
    //     printf("\n");
    // }
    

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