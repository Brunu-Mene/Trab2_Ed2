#ifndef UTILITARIOS_H
#define UTILITARIOS_H

#include "../include/str.h"
#include "../include/suffix.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/**
* @brief: Funcao para capturar entrada de arquivo e retornar tipo String unitaria contendo todo o texto tratado;
* @param adress: Caminho do arquivo de entrada;
* @return: Tipo String preenchido;
*/
String* converteArquivo(char *adress);

/**
* @brief: Funcao para realizar a abertura de um arquivo binario;
* @param adress: Ponteiro de char com caminho do arquivo;
* @return: ponteiro tipo FILE aberto para leitura;
*/
FILE *abreArquivo(char *adress);

/**
* @brief: Funcao para armazenar dinamicamente na memoria heap um ponteiro de char;
* @param tam: Tamanho da string a ser alocada;
* @return: Respectivo ponteiro alocado;
*/
char *alocaString(long long unsigned tam);

/**
* @brief: Funcao para capturar a string passada pelo usuario no parametro r;
* @return: retorna a string alocada em um ponteiro de char;
*/
char* capturaString();

/**
* @brief: Funcao que libera qualquer tipo de ponteiro;
* @param pointer: recebe um ponteiro qualquer;
*/
void liberaPonteiro(void *pointer);

/**
* @brief: Essa funcao possui um switch case que faz o tratamente dos argumentos de entrada e seleciona corretamente as funcoes correspondentes;
* @param arraySuff: um array de sufixos que contem todos os sufixos lidos do texto;
* @param N: inteiro que representa a quantidade de caracteres do texto principal;
* @param argv: inteiro que representa a quantidade de argumentos passados na execucao do programa;
* @param parametros: ponteiro de ponteiro que contem todos os argumentos passados na execucao do programa;
*/
void relatorios(Suffix **arraySuff, int N,int argv, char **parametros);

/**
* @brief: Funcao para contabilizar o tempo gasto na ordenacao do vetor de suffix;
* @param arraySuff: Vetor a ser ordenado 
* @param N: Tamanho do vetor a ser ordenado;
* @param sort: Boleano para determinar a escolha do algoritmo de ordenacao;
*/
void contabilizaTempo(Suffix **arraySuff, int N, bool sort);

#endif