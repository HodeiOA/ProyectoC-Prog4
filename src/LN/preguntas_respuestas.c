#include "preguntas_respuestas.h"
#include <stdlib.c>

t_pregunta_respuestas prepararRespuestas()
{
	t_pregunta_respuestas pregunta;
	char* respuestas[3];
	int i = 2;
	int igual = 0;
	int r;
	int random[3];

	random[0] = -1;
	random[1] = -1;
	random[2] = -1;

	while(i>=0)
	{
		igual = 0;
		r = rand() % 3;

		for(int j = 0; j<3; j++)
		{
			if(r == random[j])
				igual = 1;
		}

		if(igual == 0)
		{
			random[i] = r;
			i--;
		}
	}

	respuestas[random[0]] = pregunta.Respuesta1;
	respuestas[random[1]] = pregunta.Respuesta2;
	respuestas[random[2]] = pregunta.Respuesta3;

	pregunta.Respuesta1 = respuestas[0];
	pregunta.Respuesta2 = respuestas[1];
	pregunta.Respuesta3 = respuestas[2];

	return pregunta;
}