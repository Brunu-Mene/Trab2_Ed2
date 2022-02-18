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
    print_substring(suf->s, suf->index, suf->s->len);
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

int compareSuffix(const void *a, const void *b){
    String *S1 = ((Suffix **)a)[0]->s;
    String *S2 = ((Suffix **)b)[0]->s;
    int indexS1 = ((Suffix **)a)[0]->index;
    int indexS2 = ((Suffix **)b)[0]->index;

    for(int i=indexS1, j=indexS2; i<S1->len ;i++, j++){
        if(S1->c[i] > S2->c[j]) return 1;
        else if(S1->c[i] < S2->c[j]) return -1;
    }
    if(indexS1 == indexS2) return 0;
    return indexS1 - indexS2;
}

void sort_suf_array(Suffix* *a, int N){
    qsort(a,N,sizeof(Suffix *),compareSuffix);
}

void shell_sort_suf_array(Suffix **a, int tam){
    int i , j ;
    int gap = 1;
    Suffix *value;

    do {
        gap = 3*gap+1;
    } while(gap < tam);
    
    do {
        gap /= 3;
        for(i = gap; i < tam; i++) {
            value = a[i];
            j = i - gap;
                
            while (j >= 0 && (compareSuffix(&value,&a[j]) == -1)) {
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j + gap] = value;
        }
    }while(gap > 1);
}

int rank(Suffix* *a, int N, String *query){
    
}