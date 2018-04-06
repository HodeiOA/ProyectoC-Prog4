#include "../INCLUDES/data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*void guardarJugador(t_jugador* jugadores,  int sizeJugadores)
{
  FILE* f;
  int c;
  char* aux1;
  char* aux2;
  char aux3[2];
  
  //abrir fichero para escritura "w"

  f = fopen("./Data/jugador.txt", "w");
  printf("Se abre el fichero\n");
  //escribir en fichero un string formateado 

  //un for en el que me recorro todo el array de jugadores de param
  //por cada hueco del array --> string: nick,puntuacion
  for(int i=0; i<sizeJugadores; i++)
  {
    //crear un string auxiliar1 a ese string dare el valor del nick en cada momento 
    //aux1 = jugadores[i].nick;
     printf("Empezamos a escribir aux1 para el usuario %i\n", i+1);
     aux1 = (char*)malloc(sizeof(char)*strlen(jugadores[i].nick));
    strcpy (aux1, jugadores[i].nick);
    printf("aux1 %s\n", aux1 );
  //crear un string auxiliar2 a la posición 0 del string auxiliar "," y a la posición 1 darle 0 o /0 
     aux3[0] = ',';
      printf(" aux3 %s\n", aux3);
     aux3[1] = '\0';
    printf(" aux3 %s\n", aux3);
    //luego hacer strcat (para concatenar) paso 1ro aux1 y 2o el aux2
  //cargarme el aux2 y que aux2 valga puntuación en cada momento
    strcat (aux1,aux3);
     printf("aux1 %s\n", aux1 );
   
     //aux2 = (char*)malloc(sizeof(char)*strlen(jugadores[i].puntuacion));
    //aux2 = (char*) jugadores[i].puntuacion;
    sprintf(aux2, "%d",  jugadores[i].puntuacion);
  //luego hacer strcat (para concatenar) paso 1ro aux1 y 2o el aux2
  //cargarme el aux2 y que valga /n en la posición 0 y en la posi 1 que valga /0
  strcat (aux1,aux2);
   printf("aux1 %s\n", aux1 );

     aux3[0] = '\n';
    aux3[1] = '\0';

  //luego hacer strcat (para concatenar) paso 1ro aux1 y 2o el aux2
  //por cada hueco --> fprintf(f, aux1, MAX_NUM (me lo  invento el max num));
  strcat (aux1,aux3);
   printf("aux1 %s\n", aux1 );
  fprintf(f, aux1, 200);
   printf("hemos hecho printf de  %s para el usuario %i\n", aux1, i );
   printf("Hacemos free de aux1\n");
   free(aux1);
   printf("Lo igualamos a NULL\n");
   aux1=NULL;
  }

  //cerrar fichero
  printf("cerramos el fichero");
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
  t_jugador* jugadores;//Hay que hacer malloc de esto!!
  int l;
  int numLineas=0;

   printf("abrimos el fichero para leer\n");
  f = fopen("jugador.txt", "r");

   //Leemos solo las lineas para poder hacer malloc
  printf("Leemos solo las lineas para poder hacer malloc%i\n", numLineas );
  while ((read = getline(&line, &len, f)) != -1) 
  {
    numLineas ++;
    printf("numLineas%i\n", numLineas );
  }

  fclose(f);

  printf("Malloc del array de jugadores a devolver ");
  jugadores = (t_jugador*)malloc(sizeof(t_jugador)*numLineas);
 
 f = fopen("jugador.txt", "r");

  printf("Segundo while ");
  //(read = getline(&line, &len, fd)) != -1)
  while ((read = getline(&line, &len, f)) != -1) 
  {
     printf("leemos la línea %s\n", line);

    for(int k = 0; k < strlen(line); k++)
    {
      //auxn[i] = line[i];
      if(line[i] == ',') break;
      i++;
    }
    printf("hacemos printf de auxn con el valor  %i\n", i);
    auxn =  (char*)malloc(sizeof(char)*(i+1));
    
    for(int k = 0; k < i; k++)
    {
       printf("metemos el caracter %c en aunxn[%i] \n",line[k], k);
        auxn[k] = line[k];
    }
    auxn[i] = '\0'; //para que sea un string

    printf("Empezamos el for de puntuacion\n");
    for(int k = i+1; k < strlen(line); k++)
    {
       if(line[k]!='\n')
        j++;
    }
     printf("j vale %i\n", j);
    auxp = (char*)malloc(sizeof(char)*j);
    l=0;

    for(int k = i+1; k < strlen(line); k++)
    {
        printf("metemos el caracter %c en aunxp[%i] \n",line[k], l);
        if(line[k]!= '\n')
        { 
          auxp[l] = line[k];
          l++;
        }
        if(l == j)
          break;
    }
    printf("sale del for\n");
   printf("hacemos malloc para  jugadores[%i].nick con el int %i \n", cont,(i+1) );
   // (char*)malloc(sizeof(char)*j);

    (jugadores[cont].nick) = (char*)malloc(sizeof(char)*(i+1));

    printf("le ponemos \\0 \n", cont);
    jugadores[cont].nick[0] = '\0'; //para que sea un string

    printf("copiamos\n");
    strcpy (jugadores[cont].nick, auxn);
    printf("jugadores[%i].nick = %s\n",cont, jugadores[cont].nick);

    sscanf (auxp, "%i", &(jugadores[cont].puntuacion));
    printf("jugadores[i].puntuacion = %i\n", jugadores[i].puntuacion);
      cont ++;
      printf("Cont: %i\n",cont );
      free(auxn);
      auxn=NULL;

      free(auxp);
      auxp=NULL;

      i = 0;
      j = 0;
  }

  printf("Salgo del while\n" );
  (*num_jugadores) = cont;
  printf("NumJugadores %i\n", *num_jugadores );
  //cerrar fichero
  fclose(f);
  printf("Hemos cerrado el fichero\n" );

  return jugadores;
}*/

void guardarJugadores(t_jugador* listaJugadores, int numElem)
{
  FILE* fichero = fopen("./Data/jugador.dat", "wb"); 

  fputc(numElem, fichero);

  fwrite(listaJugadores, sizeof(t_jugador), numElem, fichero);

  fclose(fichero);
}

int numJugadoresTotal()
{
  int numElem;

  FILE* fichero = fopen("./Data/jugador.dat", "rb");

  if(fichero != NULL)
  {
    numElem = fgetc(fichero);
  } else
  {
    numElem = 0;
  }

  fclose(fichero);

  return numElem;
}

t_jugador* leerJugadores()
{
  t_jugador* listaJugadores;
  int numElem = 0;
  
  FILE* fichero = fopen("./Data/jugador.dat", "rb");

  listaJugadores = (t_jugador*) malloc(sizeof(t_jugador));

  if(fichero != NULL)
  {
    numElem = fgetc(fichero);

    listaJugadores = (t_jugador*) realloc(listaJugadores, numElem * sizeof(t_jugador));

    fread(listaJugadores, sizeof(t_jugador), numElem, fichero);
  }

  fclose(fichero);
  
  return listaJugadores;
}


void guardarPreguntaRespuestas(t_pregunta_respuestas* PreguntasParaGuardar, int numNuevas)
{
  t_pregunta_respuestas* TodasPreguntas;
  int numPreguntas;

  numPreguntas = numNuevas + numPreguntasEnFichero();

  TodasPreguntas = leerPreguntasRespuestas();

  TodasPreguntas = (t_pregunta_respuestas*) realloc(TodasPreguntas, numPreguntas * sizeof(t_pregunta_respuestas));

  for(int i = 0; i < numNuevas; i++)
  {
    TodasPreguntas[numPreguntas - numNuevas + i] = PreguntasParaGuardar[i];
  }

  FILE* fichero = fopen("./Data/PreguntaRespuestas.dat", "wb");  

  fputc(numPreguntas, fichero);

  fwrite(TodasPreguntas, sizeof(t_pregunta_respuestas), numPreguntas, fichero);

  fclose(fichero);
}

int numPreguntasEnFichero()
{
  int numElem;

  FILE* fichero = fopen("./Data/PreguntaRespuestas.dat", "rb");

  if(fichero != NULL)
  {
    numElem = fgetc(fichero);
  } else
  {
    numElem = 0;
  }

  fclose(fichero);

  return numElem;
}

t_pregunta_respuestas* leerPreguntasRespuestas()
{
  t_pregunta_respuestas* PreguntasLeidas;
	int numElem = 0;
	
  FILE* fichero = fopen("./Data/PreguntaRespuestas.dat", "rb");

  PreguntasLeidas = (t_pregunta_respuestas*) malloc(sizeof(t_pregunta_respuestas));

  if(fichero != NULL)
  {
    numElem = fgetc(fichero);

    PreguntasLeidas = (t_pregunta_respuestas*) realloc(PreguntasLeidas, numElem * sizeof(t_pregunta_respuestas));

    fread(PreguntasLeidas, sizeof(t_pregunta_respuestas), numElem, fichero);
  }

  fclose(fichero);
  
  return PreguntasLeidas;
}