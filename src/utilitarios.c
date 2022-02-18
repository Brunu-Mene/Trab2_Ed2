#include "../include/utilitarios.h"

String* converteArquivo(char *adress){
    FILE *arq = abreArquivo(adress);
    long long unsigned int tam, i = 0;
    bool aux = false;
    fscanf(arq,"%lld\n",&tam);
    char *megaString = alocaString(tam);
    char c;
    while(fscanf(arq,"%c",&c) == 1){
        if(c != ' ' && c != '\n'){
            megaString[i] = c;
            aux = true;
            i++;
        }else if((c == '\n' || c == ' ') && (aux == true)){
            megaString[i] = ' ';
            aux = false;
            i++;
        }
    }
    if(megaString[i-1] == ' ') 
        megaString[i-1] = '\0';

    String *string = create_string(megaString);
    liberaPonteiro(megaString);
    fclose(arq);
    return string;
}

FILE *abreArquivo(char *adress){
    FILE *arq = fopen(adress,"r");
    if(arq == NULL){
        printf("Erro na abertura do arquivo de entrada!\n");
        exit(1);
    }
    return arq;
}

char *alocaString(long long unsigned tam){
    char *string = calloc((tam+1),sizeof(char));
    if(string == NULL){
        printf("Erro durante a alocação de uma string!\n");
        exit(1);
    }
    return string;
}

void liberaPonteiro(void *pointer){
    free(pointer);
}