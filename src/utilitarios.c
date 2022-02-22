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

char* capturaString(){
    char sAux[150];
    for(int i=0; i<150 ;i++) sAux[i] = '\0';
    scanf("%[^\n]",sAux);
    char *s = strdup(sAux);

    return s;
}

void liberaPonteiro(void *pointer){
    free(pointer);
}

void relatorios(Suffix **arraySuff, int N, char comando, String *query, int context){
    if(comando ==  'a'){
        print_suf_array(arraySuff, N);
    }
    else if (comando == 'o'){
        //shell_sort_suf_array(arraySuff, N);
        sort_suf_array(arraySuff, N);
        print_suf_array(arraySuff, N);
    }
    else if(comando == 'r'){
        Suffix **arraySuffAux = create_suf_array(arraySuff[0]->s, N);
        contabilizaTime(arraySuff, N, true);
        contabilizaTime(arraySuffAux, N, false);

        destroy_suf_array(arraySuffAux, N);
    }
    else if(comando == 'c'){
        sort_suf_array(arraySuff, N);
        rank(arraySuff, query, buscaBinSuff(arraySuff,0,N-1,query), N, context);
    }
    else if(comando == 's'){ 
        sort_suf_array(arraySuff, N);
        while(1){
            char *queryAux = capturaString();
            getchar();
            if(strcmp(queryAux,"") == 0){
                liberaPonteiro(queryAux);
                break;
            }
            query = create_string(queryAux);
            rank(arraySuff, query, buscaBinSuff(arraySuff,0,N-1,query), N, context);
            printf("\n");
            destroy_string(query);
            liberaPonteiro(queryAux);
        }
    }             
}

void contabilizaTime(Suffix **arraySuff, int N, bool sort){
    clock_t t_init,t_final;

    t_init = clock();
    if(sort == true){
        sort_suf_array(arraySuff, N);
        printf("Quick Sort\t");
    }else{
        shell_sort_suf_array(arraySuff, N);
        printf("Shell Sort\t");
    }
    t_final = clock();
    
    printf("%.3f (s)\n",(float)(t_final - t_init)/1000000);
}