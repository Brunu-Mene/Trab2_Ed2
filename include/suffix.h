#ifndef SUFFIX_H
#define SUFFIX_H

#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    String *s;
    int index;
} Suffix;


/**
* @brief:Funcao para alocar e preencher uma estrutura de Suffix;
* @param s: Conteudo de String a ser armazenado dentro do suffix; 
* @param index: Inteiro para determinar a posicao de comeco do suffix em questao;
* @return: Ponteiro alocado e preenchido do tipo Suffix;
*/
Suffix* create_suffix(String *s, int index);


/**
* @brief: Libera da memoria um ponteiro de Suffix previamente alocado;
* @param suf: Ponteiro a ser liberado;
*/
void destroy_suffix(Suffix *suf);


/**
* @brief: Imprime no terminal o conteudo de um ponteiro de Suffix previamente alocado e preenchdio;
* @param suf: Ponteiro a ter conteudo exibido
*/
void print_suffix(Suffix *suf);


/**
* @brief: Funcao para criar/alocar/preencher um vetor de ponteiros de suffixos;
* @param text: Conteudo a ser copiado para dentro dos suffixos;
* @param N: Tamanho do vetor;
* @return: Retorno do vetor de ponteiros ja inicializado;
*/
Suffix** create_suf_array(String *text, int N);


/**
* @brief: Funcao para liberar da memoria uma estrutura vetorial de ponteiros de suffixos;
* @param a: A estrutura a ser liberada;
* @param N: Tamanho do vetor;
*/
void destroy_suf_array(Suffix* *a, int N);


/**
* @brief: Imprime no terminal a estrtura de vetor de ponteiros ja inicializada;
* @param a: A estrutura a ser exibida;
* @param N: Tamanho do vetor;
*/
void print_suf_array(Suffix* *a, int N);


/**
* @brief: Funcao para comparar alfabeticamente o conteudo de dois suffixos;
* @param a: Ponteiro contendo o primeiro elemento da comparacao;
* @param b: Ponteiro contendo o segundo elemento da comparacao;
* @return: Inteiro resultante da comparacao alfabetica entre dois suffixos;
*/
int compareSuffix(const void *a, const void *b);


/**
* @brief: Funcao para realizar a ordenacao da estrutura vetorial de suffixo com base no algoritmo qSort;
* @param a: um array de sufixos que contem todos os ponteiros de sufixos lidos do texto;
* @param N: inteiro que contem o tamanho do array de sufixos;
*/
void sort_suf_array(Suffix* *a, int N);


/**
* @brief: Funcao que ordena alfabeticamente o vetor de sufixos utilizando o algoritmo shellsort;
* @param a: um array de sufixos que contem todos os ponteiros de sufixos lidos do texto;
* @param N: inteiro que contem o tamanho do array de sufixos;
*/
void shell_sort_suf_array(Suffix **a, int N);


/**
* @brief:   Funcao recursiva que comeca sempre no meio de vetor e busca nesse 
            vetor a posicao da primeira ocorrencia da query passada como parametro;
* @param a: um array de sufixos que contem todos os sufixos lidos do texto;
* @param begin: inteiro que representa onde a busca deve comecar;
* @param N: inteiro que representa a quantidade de caracteres do texto principal;
* @param query: estrutura string que contem a palavra a ser buscada no texto;
* @return: inteiro que representa a primeira posicao da ocorrencia da query;
*/
int buscaBinSuff(Suffix* *a, int begin, int N, String *query);

/**
* @brief:   Recebe a posicao inicial da ocorrencia da query passada 
            pelo usuario e imprime todas as ocorrencias dessa string 
            no texto junto com n caracteres antes de depois da string, 
            onde n eh o valor do contexto;
* @param a: um array de sufixos que contem todos os sufixos lidos do texto;
* @param query: estrutura string que contem a palavra a ser buscada no texto;
* @param begin: inteiro que representa a posicao no array de sufixos da primeira ocorrencia da query;
* @param N: inteiro que representa a quantidade de caracteres do texto principal;
* @param context: inteiro que representa quantidade de caracteres que serao impressos antes e depois da query;
*/
void rank(Suffix **a, String* query, int begin, int N, int context);


#endif
