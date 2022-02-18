#include <stdio.h>
#include "../include/utilitarios.h"
#include "../include/suffix.h"

int main(int argv, char **args){
    String* textoString = converteArquivo(args[1]);
    Suffix **suf = create_suf_array(textoString, textoString->len);
    print_suf_array(suf,textoString->len);


    
    destroy_suf_array(suf, textoString->len);
    destroy_string(textoString);
    return 0;
}