#include "ByteEater.h"
#include "File.h"

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		LOG("ERRORE")
		return 0;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			// std::cout << "Argument " << (i + 1) << ": " << argv[i]<<std::endl;
			if (Convert)
				if (!trascrizione(argv[i]))
				{
					LOG("Errore Trascrizione");
				}
				else
				{
					LOG("Effettuato");
				}

			// LOG("Parte 2");
			if (DeConvert)
				if (!deTrascrizione(argv[i]))
				{
					LOG("Errore Trascrizione");
				}
				else
				{
					LOG("Effettuato");
				}
		}
	}

	return 1;
}