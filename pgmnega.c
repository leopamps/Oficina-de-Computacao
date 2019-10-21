//LeonardoDavi Pamplona GRR20170027
#include "estrutura.h"

int main(int argc,char * const argv[])
{
	pgm *img;
	parametros *param = entrada(argc, argv);
	le_imagem(param->input, img);
	escreve_img(stdout, img);
	nega(img);
}

