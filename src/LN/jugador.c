#include "../INCLUDES/jugador.h"
#include "../INCLUDES/data.h"
#include <string.h>

t_jugador crearJugador(char* Nick)
{
	t_jugador Jugador;
	strcpy(Jugador.nick, Nick);
	Jugador.puntuacion = 0;

	return Jugador;
}

void sumarPunto(t_jugador* Jugador)
{
	(*(Jugador)).puntuacion += 1;
}

void actualizarPuntuacion(t_jugador* listaJugadores, int numElem)
{
	t_jugador* listaJugadoresFich;
	int numFich;

	numFich = numJugadoresTotal(); 

	listaJugadoresFich = (t_jugador*) leerJugadores();

	for(int i = 0; i < numFich; i++)
	{
		for(int j = 0; j < numElem; j++)
		{
			if(strcmp((*(listaJugadoresFich + i)).nick, (*(listaJugadores + j)).nick) == 0)
			{
				(*(listaJugadoresFich + i)).puntuacion += (*(listaJugadores + j)).puntuacion;
			}
		}
	}

	guardarJugadores(listaJugadoresFich, numFich);
}