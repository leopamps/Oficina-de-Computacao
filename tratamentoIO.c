#include"tratamentoIO.h"

parametros *entrada(int argc,char * const argv[])
{

    int opt;
    parametros *param;

	while ((opt = getopt(argc, argv, "i:o:")) != -1) {    //leitura via terminal da img q será aberta e de seu destino
        switch (opt) {
            case 'i':
    			param->input = fopen(optarg,"r");
         		break;
            
            case 'o':
                param->output = fopen(optarg,"w");
                break;
            
            case 'a' :
                param->angulo = atof(optarg);
        }
    }
    return param;
}