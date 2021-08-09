#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>

#include "calc_pos_fix_converter.h"

#pragma warning(disable : 4996)

int main()
{
    setlocale(LC_ALL, "");

    Pilha pilha_operando_operador; inicializarPilha(&pilha_operando_operador);
    Pilha pilha_operadores; inicializarPilha(&pilha_operadores);
    Pilha pilha_pos_fixa; inicializarPilha(&pilha_pos_fixa);

    int qtdParenteseAberto = 0;
    int qtdParentesefechado = 0;
    char expressao[100];
    bool valida = false;

    do
    {
        setbuf(stdin, NULL);

        printf("\nDigite uma expressão (digite 0 para sair): "); scanf(" %[^\n]s", expressao);

        if (expressao[0] != '0')
        {
            valida = fragmentarString(expressao, &pilha_operando_operador);

            if (valida)
            {
                converterPosfixa(&pilha_operando_operador, &pilha_operadores, &pilha_pos_fixa);
                exibir(&pilha_pos_fixa);
            }
            else
                printf("\nExpressão Invalida !\n");
        }

        //limpar todos os elemnetos das pilhas para reutilização.
        reinicializarPilha(&pilha_operando_operador);
        reinicializarPilha(&pilha_operadores);
        reinicializarPilha(&pilha_pos_fixa);

    } while (expressao[0] != '0');


    return 0;
}