#ifndef UTILIDADES_H
#define UTILIDADES_H

	#include <string.h>
	#include <stdio.h>

	void mostratMensaje(char * str);
	//void mostrarPregunta(t_pregunta_respuesta preg);
	//void mensajeGanador(t_jugador ganador);
	//void mensajeEmpate(t_jugador* empatados);
	void recogerString (char** punt_string);
	void recogerNick (char** punt_nick);
	void recogerInt (int* punt_numero);
	int recogerRespuesta (char respuesta);


#endif