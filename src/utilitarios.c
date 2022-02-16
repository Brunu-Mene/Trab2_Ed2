#include "../include/utilitarios.h"

String* le_arquivo(char *adress){
    FILE *arq = abreArquivo(adress);
    long long unsigned int tam, i = 0;
    int aux = 0;
    fscanf(arq,"%lld\n",&tam);
    char *megaString = calloc((tam+1),sizeof(char));
    char c;
    while(fscanf(arq,"%c",&c) == 1){
        if(c != ' ' && c != '\n'){
            megaString[i] = c;
            aux = 1;
            i++;
        }else if((c == '\n' || c == ' ') && (aux == 1)){
            megaString[i] = ' ';
            aux = 0;
            i++;
        }
    }
    if(megaString[i-1] == ' ') megaString[i-1] = '\0';
    String *string = create_string(megaString);
    free(megaString);
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

void merge_string(){

}