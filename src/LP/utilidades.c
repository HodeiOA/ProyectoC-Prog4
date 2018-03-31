#include "utilidades.h"


void mostratMensaje(char* str)
{
	printf("%s",str );
}
/*
//Estos métodos habrá que ver si compilan cuando estén las estructuras hechas, los demás compilan
void mostrarPregunta(t_pregunta_respuesta preg)
{
	printf("%s", preg.pregunta);
}

void mensajeGanador(t_jugador ganador) //A este método se le llamará antes de actualizar las puntuaciones, con lo que la puntuación será la acumulada en esa partida
{
	printf("El jugador ganador de esta partida ha sido %s con %i puntos. ¡Enhorabuena! \n", ganador.nick, ganador.puntuacion );
}

void mensajeEmpate(t_jugador* empatados)//Recibe una lista con los jugadores que han empatado
{
	char* nicks_empate;

	printf("Se ha producido un empate entre %i jugadores con %i puntos ", strlen(empatados), empatados[0].puntuacion);

	for(int i=0; i < strlen(empatados); i++ )
	{
		printf("%s\n", empatados[i]);
	}
	printf("Si deseas desempatar pulsa 1\nSi deseas finalizar la partida con empate pulsa 2\n");
}
*/

// Al usar los siguientes métodos, como parámetro pasar &variable--------------
void recogerString (char** punt_string, int max_long)
{
	char str[max_long];
	char str_sin_salto_linea[];
	fgets(str, max_long, stdin);

	clear_if_needed(str);
	sscanf(str, "%s", str_sin_salto_linea); //eliminar el \n final

	//reservar solo el espacio necesario para el string
    (*punt_string) = (char *)malloc((strlen(str_sin_salto_linea) + 1) * sizeof(char)); //Le ponemos +1 para dejar espacio al \0
    strcpy((*punt_string), str_sin_salto_linea );
}

void recogerNick (char** punt_nick)
{
	printf("Indica el nick del jugador: \n");
	recogerString(punt_nick, 20);//los nicks tendrán un máximo de 20 caracteres
}

void recogerInt (int* punt_numero)
{
	scanf("%i",punt_numero);
}

//-----------------------------
/*
El método recibe la variable en la que guardaremos el resultado introducido por el usuario (a, b o c, ya que todas las preguntas tendrán tres opciones)
Devolverá un int indicando si la opción introducida concuerda con alguna de las tres letras (0: si es una respuesta posible, -1: si es una respuesta no posible)
*/
int recogerRespuesta (char respuesta) 
{
	int error=0;
	scanf("%c",&respuesta);
	if(respuesta!='a' && respuesta!='b' && respuesta!='c') 
	{
		printf("La respuesta no es válida. Por favor, introduce una opción válida (a, b o c) \n");
		error=-1;
	}
	return error;
}

/**
	Esta funcion elimina los caracteres pendientes si es necesario
	Se usa junto con fgets para leer la entrada hasta cierta longitud
*/
void clear_if_needed(char *str)
{
	if (str[strlen(str) - 1] != '\n')
	{
		int c;    
    	while ( (c = getchar()) != EOF && c != '\n');//Como leemos de teclado, usamos getchar (de fichero fgetc)
    }
}