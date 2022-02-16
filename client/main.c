#include <stdio.h>
#include "../include/utilitarios.h"

int main(int argv, char **args){
    String* teste = le_arquivo(args[1]);
    print_string(teste);
    printf("Tamanho: %d\n",teste->len);
    destroy_string(teste);
    return 0;
}