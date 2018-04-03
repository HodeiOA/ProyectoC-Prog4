#ifndef PREGUNTAS_RESPUESTAS_H
#define PREGUNTAS_RESPUESTAS_H

typedef struct
{
	char* Pregunta;
	char* Respuesta1;
	char* Respuesta2;
	char* Respuesta3;

} t_pregunta_respuestas;

t_pregunta_respuestas prepararRespuestas();

#endif