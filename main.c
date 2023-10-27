#include <stdio.h>
#include <stdlib.h>

void Erro(char msg[])
{
    system("cls");
    system("color 4F");
    printf("%s", msg);
    system("pause");
}

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

int EncontrarPosicaoLetras(char letra)
{
    char letras[52] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z'};
    for(int i = 0; i < 52; i++)
        if(letra == letras[i]) return i;
    return -1;
}

char CriptografarCaractere(char cAberto, char cPalavraChave, char ** TabulaRasa)
{
    int posAberto = EncontrarPosicaoLetras(cAberto);
    int posChave = EncontrarPosicaoLetras(cPalavraChave);
    if(posAberto == -1 || posChave == -1) return NULL;

    return TabulaRasa[posChave][posAberto];
}

char * CriptografarMensagem(char * mensagemAberta, char * palavraChave, char ** TabulaRasa)
{
    int tamMsgAberta = stringLength(mensagemAberta);
    int tamPalavraChave = stringLength(palavraChave);
    char * stringCriptografada = (char *)malloc(tamMsgAberta * sizeof(char));
    char caractere;
    int i = 0, j = 0, countCaracteres = 0;

    while(i < tamMsgAberta)
    {
        if(j == tamPalavraChave) j = 0;
        if(mensagemAberta[i] == ' ')
        {
            i++;
            continue;
        }
        caractere = CriptografarCaractere(mensagemAberta[i],palavraChave[j],TabulaRasa);
        if(caractere == NULL)
        {
            Erro("Caractere retornou nulo!\n");
            exit(-1);
        }
        stringCriptografada[countCaracteres] = caractere;
        j++;
        i++;
        countCaracteres++;
    }
    stringCriptografada[countCaracteres] = '\0';
    return stringCriptografada;
}

int main() {
    char **TabulaRasa = NULL;
    char * MsgAberta;
    char * PalavraChave;
    char * MsgCriptografada;

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

    system("cls");
    printf("--- Tabula Rasa --- \n\n");
    printf("Digite a mensagem aberta:\n");
    fgets(MsgAberta , 500, stdin);
    fflush(stdin);
    AjustarTamanhoString(MsgAberta);

    system("cls");
    printf("--- Tabula Rasa --- \n\n");
    printf("Digite a palavra chave:\n");
    fgets(PalavraChave , 500, stdin);
    fflush(stdin);
    AjustarTamanhoString(PalavraChave);

    MsgCriptografada = CriptografarMensagem(MsgAberta, PalavraChave, TabulaRasa);

    system("cls");
    printf("--- Tabula Rasa --- \n\n");
    printf("Mensagem Criptografada :\n");
    printf("%s\n", MsgCriptografada);
    return 0;
}