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
    
    for(int i=indexS1, j=indexS2; i < S1->len && j < S2->len ;i++, j++){
        char c1 = toupper(S1->c[i]);
        char c2 = toupper(S2->c[j]);
        if(c1 > c2) return 1;
        else if(c1 < c2) return -1;
    }
    return indexS1 - indexS2;
}

void sort_suf_array(Suffix* *a, int N){
    qsort(a,N,sizeof(Suffix *),compareSuffix);
}

void shell_sort_suf_array(Suffix **a, int N){
    int i , j ;
    int gap = 1;
    Suffix *value;

    do {
        gap = 3*gap+1;
    } while(gap < N);
    
    do {
        gap /= 3;
        for(i = gap; i < N; i++) {
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

int buscaBinSuff(Suffix* *a, int begin, int N, String *query){
    if(begin > N){
        return -1;
    }
    int index = (N + begin)/2;

    if(compare_from(a[index]->s, query, a[index]->index, 0) == 0){
        int decrementador = 0;
        for(int i = index - 1; i >= 0 ;i--){
            if(compare_from(a[i]->s, query, a[i]->index, 0) == 0){
                decrementador++;
            }else break;
        }
        return index - decrementador;
    }else if(compare_from(a[index]->s, query, a[index]->index, 0) == 1){
        return buscaBinSuff(a, begin, index - 1, query);
    }else{
        return buscaBinSuff(a, index + 1, N, query);
    }

}

void ocorrenciasQuery(Suffix **a, String* query, int begin, int N, int context){
    if(begin == -1){
        printf("String nao encontrada!\n");
        return;
    }
    for(int i = begin; i < N; i++){
        if(compare_from(a[i]->s, query, a[i]->index, 0) != 0){
            break;
        }
        int min = 0 > a[i]->index - context ? 0 : a[i]->index - context;
        int max = N < a[i]->index + query->len + context ? N : a[i]->index + query->len + context;
        print_substring(a[i]->s, min, max);
        printf("\n");
    }
}
