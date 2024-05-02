#include "File.h"
#include "ByteEater.h"

bool trascrizione(char *nome)
{
	std::string filename = PREFIX;
	filename = filename + nome + EXTENTION;

	FILE *B = fopen(nome, "rb");			// Lettura Binario
	FILE *T = fopen(filename.c_str(), "w"); // Scrittura Text

	if (B == NULL || T == NULL)
		return false;

	char byte;
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
	std::string filename = PREFIX;

	filename = filename + nome;
	FILE *B = fopen(filename.c_str(), "wb"); // Lettura Binario
	filename = filename + EXTENTION;
	FILE *T = fopen(filename.c_str(), "r"); // Scrittura Text

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