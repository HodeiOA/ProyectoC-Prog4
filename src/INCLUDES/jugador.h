#ifndef JUGADOR_H
#define JUGADOR_H

typedef struct
{
	char* nick;
	int puntuacion;

} t_jugador;

t_jugador crearJugador(char* Nick);
void sumarPunto(t_jugador* Jugador);
int existeJugador(t_jugador* listaJugadores, char* Nick); // No creo que este deba estar aquí...
void actualizarPuntuacion(t_jugador* listaJugadores, int numElem);

#endif