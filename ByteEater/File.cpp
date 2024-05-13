#include "File.h"
#include "ByteEater.h"

void int2Hexc(int i, char *hexA, char *hexB)
{
	const char hexList[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	int f = i / 16;
	int s = i % 16;
	*hexA = hexList[f];
	*hexB = hexList[s];
}

int Hexc2int(char hexA, char hexB)
{
	int f = 0;
	int s = 0;

	//* Controllo la prima lettera
	int check = hexA - 'A';
	if (check > 5)
	{
		LOG("Hex ERROR")
	}
	if (check >= 0)
	{
		f = (10 + check) * 16;
	}
	else
		f = (hexA - '0') * 16;

	//* Controllo la seconda lettera
	check = hexB - 'A';
	if (check > 5)
	{
		LOG("Hex ERROR")
	}
	if (check >= 0)
	{
		s = (10 + check);
	}
	else
		s = (hexB - '0');

	return f + s;
}

bool trascrizione(char nome[])
{
	std::string filename = PREFIX;
	filename = filename + nome + EXTENTION;

	FILE *B = fopen(nome, "rb");			// Lettura Binario
	FILE *T = fopen(filename.c_str(), "w"); // Scrittura Text

	if (B == NULL || T == NULL)
		return false;

	char byte = 0;
	char hexA = '0';
	char hexB = '0';
	while (fread(&byte, sizeof(char), chunk, B) == 1)
	{
		//? LOG((int)byte);
		int2Hexc((int)byte + 128, &hexA, &hexB);
		//* -128 <= (int)byte =< 127
		fprintf(T, "%c%c", hexA, hexB); //%c
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

	char hexA = '0';
	char hexB = '0';
	while (fscanf(T, "%c%c", &hexA, &hexB) > 0)
	{
		char t = (char)(Hexc2int(hexA, hexB) - 128);
		//* -128 <= (int)byte =< 127
		// LOG(t)
		fwrite(&t, sizeof(char), chunk, B);
	}

	fclose(B);
	fclose(T);
	return true;
}

/*
// Decimale
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
*/