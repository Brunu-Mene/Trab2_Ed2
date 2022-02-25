#include "../include/utilitarios.h"
#include "../include/suffix.h"

int main(int argv, char **args){
    if(argv < 3){
        printf("Erro na passagem de parametros!\n");
        exit(1);
    }
    String *textoString = converteArquivo(args[2]);
    Suffix **arraySuf = create_suf_array(textoString, textoString->len);
    relatorios(arraySuf, textoString->len,argv, args);

    destroy_suf_array(arraySuf, textoString->len);
    destroy_string(textoString);
    
    return 0;
}