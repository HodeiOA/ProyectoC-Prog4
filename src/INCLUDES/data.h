#ifndef DATA_H
#define DATA_H

#include <string.h>

void guardarJugador(t_jugador* jugadores,  int sizeJugadores);
t_jugador* leerJugador(int* num_jugadores);
void guardarPreguntaRespuestas(t_pregunta_respuestas PreguntasParaGuardar[], int numPreguntas);
void leerPreguntaRespuestas(int* numPreguntas);



#endif