#ifndef UTILIDADES_H
#define UTILIDADES_H

	#include <string.h>
	#include <stdio.h>
	#include <stdlib.h>

	void mostratMensaje(char * str); //bien
	//Descomentar y probar cuando se hayan hecho las estructuras
	//void mostrarPregunta(t_pregunta_respuesta preg);
	//void mensajeGanador(t_jugador ganador);
	//void mensajeEmpate(t_jugador* empatados);
	void recogerString (char** punt_string, int max_long);//Falta solucionar lo de \0
	void recogerNick (char** punt_nick);//bien
	void recogerInt (int* punt_numero);//birn
	int recogerRespuesta (char* respuesta);//bien
	void clear_if_needed(char *str);

#endif