#include <stdio.h>
#include <stdlib.h>


typedef struct no
{
	int chave;
	struct no *pai;
	struct no *esq;
	struct no *dir;
	int fator;
	int altura;
	int peso;
} no;


no *cria_no (int chave)
{
	no *n = malloc(sizeof(no));
	n -> chave = chave;
	n -> esq = NULL;
	n -> dir = NULL;
	n-> pai = NULL;
	n-> fator = 0;
	n->altura = -1;
	n->peso = 0;
	return (n);
} 

  
no *insere (no *n, int valor)
{	
	if ( n == NULL )
		return ( cria_no (valor));
	
	if (n->chave == valor)
	{
		if (n-> pai !=NULL)
			return (n-> pai);
		else
			return (n);
	}

	if ( n ->chave > valor )
	{	
		if (n->esq == NULL)
		{
			n->esq = cria_no(valor);
			n->esq->pai = n;		
		}
		else
			insere (n->esq, valor);			
	}
	
	else
	{
		if (n-> dir == NULL)
		{
			n-> dir = cria_no(valor);
			n-> dir-> pai = n;
		}
		else
			insere (n->dir, valor);			
	}
	
	if (n-> pai !=NULL)
		return (n-> pai);
	else
		return (n);
}


void altura(no *n)
{
	if(!n)
		return;

	if(!n->pai)
		n->altura = 0;
	else
		n->altura = n->pai->altura + 1;
	altura(n->esq);
	altura(n->dir);
}


void balanceamento (no *n)
{
	if(n != NULL)
	{
        if(n->esq!=NULL)
        {
        	balanceamento (n-> esq);
        	if(n->dir==NULL)
        		if (n->esq->altura==0)
        			n->fator= n->esq->fator -1;
        		else
        			n->fator =  - n->altura ;
        }



        if(n->dir!=NULL)
        {
    	    balanceamento (n-> dir);
    	    if(n->esq==NULL)
    	    	if (n->dir->altura==0)
        			n->fator= n->dir->fator +1;
        		else
        			n->fator =  n->altura  ;
    	}

    	if ( n->esq != NULL)
  		{
        	if (n-> dir != NULL){
        		n->fator =  n->dir->altura - n->esq->altura;
 			}
        }
    }
}



void emordem (no *n,int nivel)
{
	nivel++;
	if(n != NULL)
	{	 
		emordem (n-> esq,nivel);
		printf("chave %d altura %d fator %d\n",n->chave,n->altura,n->fator);
		emordem (n-> dir,nivel);
	}
}

void rotacao(no *n)
{
	if(n !=NULL)
	{
		if(n->fator==2){
			n->dir->peso=1;
			rotacao(n->dir);
		}
		if(n->fator==-2){
			n->esq->peso=-1;
			rotacao(n->esq);
		}
		if(n->fator==1){
			if(n->peso==1) printf("Rotação simples em %d\n",n->chave );
			if(n->peso==-1) printf("Rotação dupla em %d\n",n->chave );
			if(n->peso==0) rotacao(n->dir);
		}
		if(n->fator==-1){
			if(n->peso==-1) printf("Rotação simples em %d\n",n->chave );
			if(n->peso==1) printf("Rotação dupla em %d\n",n->chave );
			if(n->peso==0) rotacao(n->esq);
		}
	}
}


int main ()
{
	no *raiz = NULL;
	
	int valor = 0;
	int nivel = -1;

	do
	{	
		scanf ("%d", &valor);
		if(valor!=0)
		raiz = insere (raiz, valor);
		altura(raiz);
		balanceamento (raiz);
		rotacao(raiz);
	} while (valor != 0) ;
	 
	
	emordem(raiz,nivel);
}