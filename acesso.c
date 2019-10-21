
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
        //  fprintf(out,"\n");
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

void nega (pgm* img)
{
	for(int i=0; i< img->linha; i++ )
		for (int j = 0; j < img->coluna; ++j)
		{
			img->matriz[i,j] = img->tom - img->matriz[i,j];
		}
}