#include "../include/utilitarios.h"
#include "../include/suffix.h"

//o 5 parametro aparenemente é passado entre aspas
int main(int argv, char **args){
    String *query = NULL;
    if(argv == 5) query = create_string(args[4]);
    String *textoString = converteArquivo(args[2]);
    Suffix **arraySuf = create_suf_array(textoString, textoString->len);
    relatorios(arraySuf, textoString->len, args[1][1], query, atoi(args[3]));

    /*sort_suf_array(arraySuf, textoString->len);
    shell_sort_suf_array(arraySuf,textoString->len);
    String *aux = create_string("the worst");
    rank(arraySuf, aux, buscaBinSuff(arraySuf,0,textoString->len-1,aux), textoString->len,15);
    destroy_string(aux);
    */

    destroy_suf_array(arraySuf, textoString->len);
    destroy_string(textoString);
    if(query !=NULL) destroy_string(query);
    return 0;
}