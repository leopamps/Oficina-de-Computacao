//LeonardoDavi Pamplona GRR20170027
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "estrutura.h"

#define MAX 10000



void pula_coment(FILE * in)
{
	// usar fgets, se identificar #, troque por \0

	if ( f=='#')
		
	char tipo_imagem[100];
	char coluna_linha[100];
	char tons[100];	
	char buffer[100];
	int set = 0;
	int i=0;
	for(char c; set < 3;){
		c = fgetc(in);
		if(c == '#'){
			for(;c!='\n';c=fgetc(in));
			i=0;
		}
		else{
			buffer[i] = c;
			++i;
		}
		if(c == '\n')
			if(set == 0){
				strcpy(tipo_imagem,buffer);
				i = 0;
				++set;
			}else
				if(set == 1){
					strcpy(coluna_linha,buffer);
					i = 0;
					++set;
				}else
					if(set == 2){
						strcpy(tons,buffer);
						i = 0;
						++set;
					}
	}
printf("%s", tipo_imagem);
printf("%s", coluna_linha);
printf("%s", tons);
}

// escrever funçao para desalocar matriz (free)


int le_imagem(FILE* in, pgm *img )
{
	int i, j;

	if (in == NULL){
		printf("ARQUIVO NAO ENCONTRADO\n");
		return (1);
	}

	// fscanf(in, "%s\n", img->tipoP);
	// fscanf(in, "%d %d\n", &(img->coluna), &(img->linha));
	// fscanf(in, "%d\n", &(img->tom) );

	// aloca um vetor de LIN ponteiros para linhas
	img->matriz = malloc (img->linha * sizeof (unsigned char*)) ;
 
	// aloca um vetor com todos os elementos da matriz
	img->matriz[0] = (malloc (img->linha * img->coluna * sizeof (unsigned char))) ;
 
	// ajusta os demais ponteiros de linhas (i > 0)
	for (i=1; i < img->linha; i++)
  		img->matriz[i] = img->matriz[0] + i * img->coluna ;
 

	if (strcmp(img->tipoP,"P2") == 0)
	{	
		//se for p2:
		for (int i = 0; i < img->linha; ++i)
		{
			for (int j = 0; j < img->coluna; ++j)
			{
				fscanf(in,"%hhu ",&(img->matriz[i][j]));
			}
		}
	}

	else
	{	
		//se for p5
		for (i=0; i < img->linha; i++)
    		fread(img->matriz[i], sizeof(unsigned char), img->coluna, in) ;
    	
	}
	return (0);
}


void escreve_img(FILE* out, pgm *img)
{	
	fprintf (out, "%s\n", img->tipoP );
	fprintf (out, "%d %d\n", img->coluna, img->linha);
	fprintf (out, "%d\n", img->tom );

	if (strcmp(img->tipoP,"P2") == 0)
	{
		for (int i = 0; i < img->linha; ++i)
		{
			for (int j = 0; j < img->coluna; ++j)
			{
				fprintf(out,"%hhu ",(img->matriz[i][j]));
			}
		//	fprintf(out,"\n");
		}
	}

	else
	{
		// percorre a matriz
		for (int i=0; i < img->linha; i++)
    		fwrite(img->matriz[i], sizeof(unsigned char), img->coluna, out) ;	
	}
	
	free(img->matriz[0]);
	free(img->matriz);
	free(img);
} 


int main(int argc,char * const argv[])
{
	entrada(argc, argv);
}



