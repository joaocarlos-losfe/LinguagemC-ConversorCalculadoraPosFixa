#pragma once

#ifndef _POSFIX_H_
#define _POSFIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct aux
{
    char elemento_expressao[10];
    struct aux* proximo_abaixo;

}ElementoOperandoOperador, * PontElementoOperandoOperador;

typedef struct
{
    PontElementoOperandoOperador topo;

}Pilha;


void inicializarPilha(Pilha* pilha);

void reinicializarPilha(Pilha* pilha);

bool vazia(Pilha* pilha);

void exibir(Pilha* pilha);

void empilhar(Pilha* pilha, char* elemento_expressao);

bool desempilhar(Pilha* pilha, char* temp_elemento_expressao);

void inverterPilha(Pilha* pilha);

bool ehOperador(char* str);

int prioridade(char* str);

bool ehNumero(char* str);

bool validarExpressao(char* str, Pilha* pilha, int* qtdParenteseAberto, int* qtdParentesefechado);

bool fragmentarString(char* str, Pilha* pilha);

void converterPosfixa(Pilha* pilha_operando_operador, Pilha* pilha_operadores, Pilha* pilha_pos_fixa);



#endif