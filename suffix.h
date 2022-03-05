#ifndef SUFFIX_H
#define SUFFIX_H

#include "str.h"

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

int comp_suf_array(const void *pa, const void * pb);

void another_suf_array(Suffix* *a, int N);

void procuraSuffix(Suffix* *a, int N, String* query, int contexto, String* texto);

int rank(Suffix* *a, int N, String *query);

#endif
