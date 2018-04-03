#include "data.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
+guardarJugador(jugador : *Jugador) : void
+leerJugador() : *Jugador
+leerPreguntas(preguntas : Pregunta_Respuesta) : void
*/

FILE * file;

//---- fichero llamado "input.txt" con jugadores y su puntuación

if ()//file es un txt
{
  leerJugador();
  leerPreguntas();
}
else //file es un binario
{

}

t_preguntasRespuestas* leerPreguntas(Pregunta_Respuesta preguntas) //este en binario
{
  file = fopen ("input.txt", "rb");
  
  if (file == NULL) 
  {
    printf("Archivo no encontrado\n");
    return -1;
  }
}

void guardarJugador(t_jugador* jugadores)
{
  FILE* f;
  int c;
  
  //abrir fichero para escritura "w"
  f = fopen("jugador.txt", "w");
  
  //escribir en fichero un string formateado 
  //un for en el que me recorro todo el array de jugadores de param
  //por cada hueco del array --> string: nick,puntuacion
  //crear un string auxiliar1 a ese string dare el valor del nick en cada momento 
  //crear un string auxiliar2 a la posición 0 del string auxiliar "," y a la posición 1 darle 0 o /0 
  //luego hacer strcat (para concatenar) paso 1ro aux1 y 2o el aux2
  //cargarme el aux2 y que aux2 valga puntuación en cada momento
  //luego hacer strcat (para concatenar) paso 1ro aux1 y 2o el aux2
  //cargarme el aux2 y que valga /n en la posición 0 y en la posi 1 que valga /0
  //luego hacer strcat (para concatenar) paso 1ro aux1 y 2o el aux2
  //por cada hueco --> fprintf(f, aux1, MAX_NUM (me lo  invento el max num));
  
  //cerrar fichero
  fclose(f);
}

leerJugador()
{
  FILE* f;
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  int cont =0;
  int puntuacion;
  string aux;

  f = fopen("jugador.txt", "r");

  while ((read = getline(&line, &len, f)) != -1) 
  {

  }

  while ((read = getline(&line, &len, f)) != -1) 
  {
    //con el cont de arriba sé cuantas lineas tengo en el fich

    //me recorro el line en un for caracter a caracter y voy guardando estos en un string hasta que llegue a la coma,
    //cuando llegue, el string se lo asigno a la posición jugadores[cont].nick del array de jugadores que voy a devolver
    //pasarlo todo a un string con scanf(puntuacion,%i, aux) //aux es el strign anterior
    //cojo todos los caracteres de después de la coma se los asigno a jugadores [cont].puntuacion

    cont ++;

  }

  //cerrar fichero
  fclose(f);

  retur t_jugador
}