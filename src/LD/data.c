#include "../INCLUDES/data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void guardarJugador(t_jugador* jugadores,  int sizeJugadores)
{
  FILE* f;
  int c;
  char* aux1;
  char* aux2;
  
  //abrir fichero para escritura "w"
  f = fopen("jugador.txt", "w");
  
  //escribir en fichero un string formateado 

  //un for en el que me recorro todo el array de jugadores de param
  //por cada hueco del array --> string: nick,puntuacion
  for(int i=0; i<sizeJugadores; i++)
  {
  	//crear un string auxiliar1 a ese string dare el valor del nick en cada momento 
  	//aux1 = jugadores[i].nick;
  	strcpy (aux1, jugadores[i].nick);
	//crear un string auxiliar2 a la posición 0 del string auxiliar "," y a la posición 1 darle 0 o /0 
  	aux2[0] = ',';
  	aux2[1] = '\0';

  	//luego hacer strcat (para concatenar) paso 1ro aux1 y 2o el aux2
	//cargarme el aux2 y que aux2 valga puntuación en cada momento
  	strcat (aux1,aux2);
  	aux2 = NULL;
	
	aux2 = (char*) jugadores[i].puntuacion;

	//luego hacer strcat (para concatenar) paso 1ro aux1 y 2o el aux2
	//cargarme el aux2 y que valga /n en la posición 0 y en la posi 1 que valga /0
	strcat (aux1,aux2);
  	aux2 = NULL;
	aux2[0] = '\n';
  	aux2[1] = '\0';

	//luego hacer strcat (para concatenar) paso 1ro aux1 y 2o el aux2
	//por cada hueco --> fprintf(f, aux1, MAX_NUM (me lo  invento el max num));
	strcat (aux1,aux2);
	fprintf(f, aux1, 200);
  }

  //cerrar fichero
  fclose(f);
}

t_jugador* leerJugador(int* num_jugadores)
{
  FILE* f;
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  int cont = 0;
  int puntuacion;
  char* auxn;
  char* auxp;
  int i = 0;
  char c;
  int j = 0;
  t_jugador* jugadores;

  f = fopen("jugador.txt", "r");

  while ((read = getline(&line, &len, f)) != -1) 
  {
 	for(int k = 0; k < strlen(line); k++)
 	{
 		auxn[i] = line[i];
 		i++;
 	}
  for (int k = 0; k <strlen(line); k++)
 	{
 		auxp[j] = line[j-i];
 		j++;
 	}
    //cuando llegue ','' el string se lo asigno a la posición jugadores[cont].nick del array de jugadores que voy a devolver
    //pasarlo todo a un string con scanf(puntuacion,%i, aux) //aux es el strign anterior
 	strcpy (jugadores[cont].nick, auxn);
 	sscanf (auxp, "%i", &(jugadores[i].puntuacion));

    cont ++;
  }


  //cojo todos los caracteres de después de la coma se los asigno a jugadores [cont].puntuacion
  (*num_jugadores) = cont;

  //cerrar fichero
  fclose(f);

  return jugadores;
}

void guardarPreguntaRespuestas(t_pregunta_respuestas PreguntaParaGuardar)
{
  FILE* fichero = fopen("PreguntaRespuestas.dat", "wb");  

  fputc(1, fichero);

  fwrite(&PreguntaParaGuardar, sizeof(t_pregunta_respuestas), 1, fichero);

  fclose(fichero);
}

int leerPreguntaRespuestas(t_pregunta_respuestas* PreguntasLeidas)
{
	int numElem;

  FILE* fichero = fopen("PreguntaRespuestas.dat", "rb");

  numElem = fgetc(fichero);

  PreguntasLeidas = (t_pregunta_respuestas*) malloc(numElem * sizeof(t_pregunta_respuestas));

  fread(PreguntasLeidas, sizeof(t_pregunta_respuestas), numElem, fichero);

  return numElem;

  fclose(fichero);
}