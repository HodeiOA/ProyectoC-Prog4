#ifndef DATA_H
#define DATA_H

	#include <string.h>
	#include "../INCLUDES/preguntas_respuestas.h"
	#include "../INCLUDES/jugador.h"

	void guardarJugador(t_jugador* jugadores,  int sizeJugadores);
	t_jugador* leerJugador(int* num_jugadores);
	void guardarPreguntaRespuestas(t_pregunta_respuestas PreguntasParaGuardar[], int numPreguntas);
	t_pregunta_respuestas* leerPreguntaRespuestas(int* numPreguntas)



#endif