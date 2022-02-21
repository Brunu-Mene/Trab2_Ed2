#ifndef SUFFIX_H
#define SUFFIX_H

#include "str.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    String *s;
    int index;
} Suffix;

Suffix* create_suffix(String *s, int index);

void destroy_suffix(Suffix *suf);

void print_suffix(Suffix *suf);

Suffix** create_suf_array(String *text, int N);

void destroy_suf_array(Suffix* *a, int N);

void print_suf_array(Suffix* *a, int N);

// Use uma (ou mais) funcoes deste tipo para ordenar
// o arry de sufixos usando o qsort e outro metodo de sua escolha
void sort_suf_array(Suffix* *a, int N);
void shell_sort_suf_array(Suffix **a, int tam);

int buscaBinSuff(Suffix* *a, int begin, int N, String *query);

void rank(Suffix **a, String* query, int begin, int N, int context);


#endif
