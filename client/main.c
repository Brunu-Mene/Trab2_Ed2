#include <stdio.h>
#include "../include/utilitarios.h"
#include "../include/suffix.h"

int main(int argv, char **args){
    String* textoString = converteArquivo(args[1]);
    Suffix **arraySuf = create_suf_array(textoString, textoString->len);
    //print_suf_array(arraySuf,textoString->len);
    //sort_suf_array(arraySuf, textoString->len);
    shell_sort_suf_array(arraySuf,textoString->len);
    print_suf_array(arraySuf,textoString->len);
    String *aux = create_string("RA");
    //printf("%d\n", aux->len);
    printf("%d\n",buscaBinSuff(arraySuf,0,textoString->len-1,aux));
    printf("%d\n",rank(arraySuf, aux, buscaBinSuff(arraySuf,0,textoString->len-1,aux), textoString->len));

    destroy_suf_array(arraySuf, textoString->len);
    destroy_string(textoString);
    return 0;
}