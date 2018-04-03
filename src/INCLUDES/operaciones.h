#ifndef OPERACOINES_H
#define OPERACOINES_H

t_pregunta_respuestas generarPregunta (t_pregunta_respuestas *arrPreg, t_pregunta_respuestas* *preguntasSalidas, int sizePreguntasSalidas, int sizeTotalPreguntas);
int comprobarRespuesta(char* respuesta);
int maxPreguntas (int cantPreguntas, int sizeTotalPreguntas);
void ordenarJugadores(t_jugador* jugadoresLeidos, int size);
int maxPuntuacion(t_jugador* jugadores, int sizeJugadores);



#endif