#include "jugador.h"

t_jugador crearJugador(t_jugador* listaJugadores, char* Nick)
{
	Jugador.nick = Nick;
	Jugador.puntuacion = 0;

	return Jugador;
}

void sumarPunto(t_jugador* Jugador)
{
	Jugador->puntuacion += 1;
}

int existeJugador(t_jugador* listaJugadores, char* Nick)
{
	// No entiendo muy bien qué hace este método. ¿Mira si existe el Jugador en la lista?
}

void actualizarPuntuacion(t_jugador* listaJugadores, int numElem)
{
	t_jugador* listaFichero;
	int numFich; // Cómo sacamos esta información??

	listaFichero = leerJugadores(); // Editar nombre método correcto

	for(int i = 0; i < numFich; i++)
	{
		for(int j = 0; j < numElem; j++)
		{
			if(*(listaFichero + i)->nick == *(listaJugadores + j)->nick)
			{
				*(listaFichero + i)->puntuacion += *(listaJugadores + j)->puntuacion;
			}
		}
	}

	guardarJugadores(listaFichero); // Editar nombre método correcto
}