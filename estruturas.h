//Leonardo Davi Pamplona GRR20170027

#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include"tratamento.h"
#include"acesso.h"

typedef struct pgm
{
	char tipoP[2];
	int linha;
	int coluna;
	int tom;
	unsigned char **matriz;

} pgm;

typedef struct parametros
{
	FILE* input;
	FILE* output;
	double angulo;
}
