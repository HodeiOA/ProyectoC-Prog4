#include "../INCLUDES/jugador.h"
#include "../INCLUDES/data.h"
#include <string.h>
#include <stdlib.h>

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
   	t_jugador* listaJugadoresGuardar;
   	//t_jugador* listaJugadoresNoFich;
   	int coincidencias = 0;
 
   	numFich = numJugadoresTotal();
 
   	listaJugadoresFich = (t_jugador*) leerJugadores();
   
   	if(numFich == 0)
   	{
         	guardarJugadores(listaJugadores, numElem);
   	}
   	else
   	{
         	for(int i = 0; i < numFich; i++)
         	{
                	for(int j = 0; j < numElem; j++)
                	{
                       	if(strcmp((*(listaJugadoresFich + i)).nick, (*(listaJugadores + j)).nick) == 0)
                       	{
                              	coincidencias ++;
                       	}
                	}
         	}
   	}
 
   	if(coincidencias == 0)
   	{
         	//Todos los jugadores que han jugado ahora son nuevos -> no hay que actualizar puntuaciones:
                	//Hay que guardar todos los leídos tal cual
                	//Hay que guardar todos los pasados tal cual
         	listaJugadoresGuardar = (t_jugador*)malloc((numElem + numFich) * sizeof(t_jugador));
         	//Llenamos la lista a guardar con los leídos:
         	for(int i=0; i<numFich; i++)
         	{
                listaJugadoresGuardar[i]=listaJugadoresFich[i];
         	}
 
         	//Llenamos la lista a guardar con el resto de jugadores, los que se han pasado por parámetro
         	for(int i=0; i<numElem; i++)
         	{
                	listaJugadoresGuardar[i + numFich]=listaJugadores[i];//Metemos los jugadores a partir de la posicion de la que dejamos de meter en el otro for
         	}
         	//(*(listaJugadoresFich + i)).puntuacion += (*(listaJugadores + j)).puntuacion;
 
         	guardarJugadores(listaJugadoresGuardar, (numFich+numElem));
 
         	free(listaJugadoresGuardar);
         	listaJugadoresGuardar = NULL;
 
   	}
   	else
   	{
         	//Si hay coincidencias, tendremos que usar la lista listaJugadoresNoFich, ya que estos se meterán tal cual, mientras a los demás se les actualizará la puntuacion en listaFich
         	//La lista a guardar ahora será más pequeña (ya que algunos jugadores están en ambas listas)
         	//Hacemos dos mallocs, de la lista a guardar y la de los que no están en el fichero:
         	//listaJugadoresNoFich = (t_jugador*)malloc((numElem - coincidencias) * sizeof(t_jugador)); //hueco para todos los pasados menos los que están en el fichero
         	listaJugadoresGuardar = (t_jugador*)malloc((numFich + numElem - coincidencias) * sizeof(t_jugador)); //guardaremos la lista de fichero y la de no en fichero, por lo que sumamos los tamaños
          	
         	//int cont_noFich = 0;
         	int coincidencia = -1;
         	//Actualizamos puntuaciones y llenamos la lista de jugadores noEnfich:
         	for(int i = 0; i < numFich; i++)
         	{
                	for(int j = 0; j < numElem; j++)
                	{
                  		if(strcmp((*(listaJugadoresFich + i)).nick, (*(listaJugadores + j)).nick) == 0)
                       	{
                        	coincidencia = j;
                       	}
                	}
                            	
                           	if(coincidencia != -1)
                            {
                              	(*(listaJugadoresFich + i)).puntuacion += (*(listaJugadores + coincidencia)).puntuacion;
                              	// Aquí empieza la solución
                              	numElem--;
                              	if(numElem > 0)
                              	{
                                	t_jugador* auxLista = (t_jugador*) malloc(numElem * sizeof(t_jugador));
                                	int r2 = 0;
                                	for (int r1 = 0; r1 < numElem; ++i)
                                	{
	                                  	if(coincidencia == r1)
	                                    	r2++;
	                                  	auxLista[r1] = listaJugadores[r2];
	                                  	r2++;
                                	}
                                	
                                	listaJugadores = (t_jugador*) realloc(listaJugadores, numElem * sizeof(t_jugador));
                                	for (int r = 0; r < numElem; r++)
                                	{
                                  		listaJugadores[r] = auxLista[r];
                                	}
                                	
                              	}
                            }
                            	coincidencia = -1;
                              	// La solución llega hasta aquí
         	}
         	//Teniendo las dos listas preparadas, las metemos en la lista a guardar:
                	//Llenamos la lista a guardar con los leídos:
                	for(int i=0; i<numFich; i++)
                	{
                		listaJugadoresGuardar[i]=listaJugadoresFich[i];
                	}
 
                	//Lllenamos el resto de la lista con los jugadores no leídos
                	for(int i=0; i<numElem; i++)
                	{
                      	//printf("\nVoy a asignar el jugador %s de listaJugadoresNoFich a la posicion %d de listaJugadoresGuardar", listaJugadoresNoFich[i].nick, (i + numFich));
                       	listaJugadoresGuardar[i + numFich]=listaJugadores[i];//Metemos los jugadores a partir de la posicion de la que dejamos de meter en el otro for
                	}

                	int aux = numFich + numElem;
                	guardarJugadores(listaJugadoresGuardar, (numFich + numElem));
         	
                	free(listaJugadoresGuardar);
                	listaJugadoresGuardar = NULL;
   	}
}
