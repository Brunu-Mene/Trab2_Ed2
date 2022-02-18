#include "../include/suffix.h"

Suffix* create_suffix(String *s, int index){
    Suffix *suf = (Suffix *) malloc(sizeof(Suffix));
    suf->s = s;
    suf->index = index;
    return suf;
}

void destroy_suffix(Suffix *suf){
    free(suf);
}

void print_suffix(Suffix *suf){
    for(int i=suf->index; i<suf->s->len ;i++){
        printf("%c",suf->s->c[i]);
    }
    printf("\n");
}

Suffix** create_suf_array(String *text, int N){
    Suffix **arraySuffix = (Suffix **) malloc(sizeof(Suffix *)*N);
    for(int i=0; i<N ;i++){
        arraySuffix[i] = create_suffix(text, i);
    }
    return arraySuffix;
}

void destroy_suf_array(Suffix* *a, int N){
    for(int i=0; i<N ;i++){
        destroy_suffix(a[i]);
    }
    free(a);
}

void print_suf_array(Suffix* *a, int N){
    for(int i=0; i<N; i++){
       print_suffix(a[i]);
    }
}

void sort_suf_array(Suffix* *a, int N){

}

int rank(Suffix* *a, int N, String *query){
    
}