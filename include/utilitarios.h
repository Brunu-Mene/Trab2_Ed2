#ifndef UTILITARIOS_H
#define UTILITARIOS_H

#include "../include/str.h"
#include "../include/suffix.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

String* converteArquivo(char *adress);
FILE *abreArquivo(char *adress);
char *alocaString(long long unsigned tam);
char* capturaString();
void liberaPonteiro(void *pointer);
void relatorios(Suffix **arraySuff, int N,int argv, char **parametros);
void contabilizaTempo(Suffix **arraySuff, int N, bool sort);

#endif