#ifndef UTILITARIOS_H
#define UTILITARIOS_H

#include "../include/str.h"
#include "../include/suffix.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

String* converteArquivo(char *adress);
FILE *abreArquivo(char *adress);
void merge_string();


char *alocaString(long long unsigned tam);
void liberaPonteiro(void *pointer);

void relatorios(Suffix **arraySuff, int N, char comando, String *query, int context);
void contabilizaTime(Suffix **arraySuff, int N, bool sort);

#endif