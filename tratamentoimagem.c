void nega(pgm *img)
{
	for (int i = 0; i < img->linha; ++i)
	{
		for (int j = 0; j < img->coluna; ++j)
		{
			img->matriz[i][j] = img->tom - img->matriz[i][j]; 
		}
	}
}