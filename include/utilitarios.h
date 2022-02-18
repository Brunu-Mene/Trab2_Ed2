#ifndef UTILITARIOS_H
#define UTILITARIOS_H

#include "../include/str.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

String* converteArquivo(char *adress);
FILE *abreArquivo(char *adress);
void merge_string();


char *alocaString(long long unsigned tam);
void liberaPonteiro(void *pointer);

#endif