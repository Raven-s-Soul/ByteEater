#include "File.h"
#include "ByteEater.h"

bool trascrizione(char *nome)
{
	FILE *B = fopen(nome, "rb");		// Lettura Binario
	FILE *T = fopen("file.Eated", "w"); // Scrittura Text

	if (B == NULL || T == NULL)
		return false;

	int byte;
	while (fread(&byte, sizeof(char), chunk, B) == 1)
	{
		// LOG( byte );
		fprintf(T, "%d ", byte); //%c
	}

	fclose(B);
	fclose(T);
	return true;
}

bool deTrascrizione(char *nome)
{
	FILE *T = fopen("file.Eated", "r"); // Scrittura Text
	FILE *B = fopen("file.pdf", "wb");	// Lettura Binario

	if (B == NULL || T == NULL)
		return false;

	int ch;
	while (fscanf(T, "%d ", &ch) > 0)
	{
		// LOG(ch)
		fwrite(&ch, sizeof(char), chunk, B);
	}

	fclose(B);
	fclose(T);
	return true;
}