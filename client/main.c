#include <stdio.h>
#include "../include/utilitarios.h"

int main(int argv, char **args){
    String* textoString = converteArquivo(args[1]);
    destroy_string(textoString);
    return 0;
}