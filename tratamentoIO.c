#include"tratamentoIO.h"

void entrada(int argc,char * const argv[])
{

	FILE * in;
    int opt;

    pgm *img;

	while ((opt = getopt(argc, argv, "i:o:")) != -1) {    //leitura via terminal da img q será aberta e de seu destino
        switch (opt) {
            case 'i':
    			in = fopen(optarg,"r");
         		//pula_coment(in);
         		 le_imagem(in, img);
         		
         		escreve_img(stdout, img);
                break;
            case 'o':
               // out = fopen(optarg,"w");
                break;
        }
    }
}