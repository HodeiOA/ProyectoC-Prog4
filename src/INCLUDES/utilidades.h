#ifndef UTILIDADES_H
#define UTILIDADES_H

	#include <string.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include "../INCLUDES/preguntas_respuestas.h"
	#include "../INCLUDES/jugador.h"

	void mostrarMensaje(char * str); //bien
	void mostrarInt(int i);
	void mostrarPregunta(t_pregunta_respuestas preg);
	void mostrarRespuestas(t_pregunta_respuestas preg);
	void mostrarPuntuacion(t_jugador jugador);
	void mensajeGanador(t_jugador ganador);
	void mensajeEmpate(t_jugador* empatados);
	void recogerString (char** punt_string, int max_long);//Falta solucionar lo de \0
	void recogerNick (char** punt_nick);//bien
	void recogerInt (int* punt_numero);//birn
	int recogerRespuesta (char* respuesta);//bien
	void clear_if_needed(char *str);

#endif