#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "INCLUDES/operaciones.h"

t_Pregunta_Respuesta *listaTodasPreguntas;

int calcularPuntos(t_jugador jugador, int * acumulada) 
{
	jugador.puntuacion = acumulada + jugador.puntuacion;
}

int sumarPunto(t_jugador jugador)
{
	jugador.puntuacion = jugador.puntuacion + 1;
}

t_pregunta_respuestas generarPregunta ( int cant_preguntas, t_pregunta_respuestas *preguntasSalidas)
{
	int random =0;
	t_pregunta_respuestas pregunta;
	t_pregunta_respuestas *arrPreg=leerPregunta();
	int repetida;
	int cont;
	int MAX_INTENTOS = 20;
	t_pregunta_respuestas *aux;
	int sizePreguntasSalidas=0;
	int sizeTotalPreguntas=0;


	//Cantidad de preguntas en cada array
 	sizePreguntasSalidas = sizeof(preguntasSalidas)/sizeof(t_pregunta_respuestas);
 	sizeTotalPreguntas = sizeof(arrPreg)/sizeof(t_pregunta_respuestas);

	srand(time(NULL));
 	for (int i = 0; i < cant_preguntas; ++i)
	 {
	 	do
	 	{
		 		random = rand() %(cant_preguntas); //genera un número aleatorio entre 0 y cant_preguntas-1
		 		pregunta = arrPreg[random];

		 		for(int j=0; j < sizePreguntasSalidas; i++)
		 		{

		 			//repetida = strcmp (pregunta.Pregunta,preguntasSalidas[i].Pregunta); //si son iguales, será 0
		 			if((strcmp (pregunta.Pregunta,preguntasSalidas[i].Pregunta))==0)
		 			{
		 				repetida = 1; //si son iguales, será 0
		 			}
		 		}
		 	cont++;
	 	}
	 	while(repetida==1 || cont ! = MAX_INTENTOS); //Hará esto hasta que encuentre una pregunta no repetida o agote la cantidad de intentos
	 
	 aux = (t_pregunta_respuestas*) malloc ((sizePreguntasSalidas+1)* sizeof(t_pregunta_respuestas));
	 //creamos espacio para las preguntas ya salidas +1 (la nueva)
	
	//metemos todas las preguntas del array de los ya salidos en la variable auxiliar
	 for (int i=0; i<sizePreguntasSalidas; i++)
	 {
	 	aux[i] = preguntasSalidas [i];
	 }
	 aux[sizePreguntasSalidas] = pregunta;//Añadimos la pregunta en la variable auxiliar

	 free (preguntasSalidas);
	 preguntasSalidas = NULL;

	 //Hacemos malloc de preguntasSalidas otra vez para darles espacio para un hueco más
	 preguntasSalidas = (t_pregunta_respuestas*) malloc ((sizePreguntasSalidas+1)* sizeof(t_pregunta_respuestas));
	 
	 for (int i=0; i<(sizePreguntasSalidas+1); i++)
	 {
	 	preguntasSalidas [i] = aux[i]; 
	 }

	 //nos libramos de aux porque ya no nos hace falta
	 free(aux);
	 aux = NULL;

	 return pregunta;
}

//Verificar si la respuesta elegida es la correcta
//(ver si la respuesta a la que se le ha asignado el valor de la letra que se ha elegido empieza por punto)
int comprobarRespuesta(char* respuesta) 
{
	int correcto;

	//si correcto es 1, ha contestado bien

	if (respuesta[0] =='.')
	{
		correcto =1;
	}
	else
	{
		correcto =0;
	}

	return correcto;
}

int maxPreguntas (int cantPreguntas) 
//leer todas las preguntas ver cuántas hay del fichero
//lo que hay del fichero pasar a array
//comparar lo del parám con la cantidad de preguntas
//para que no me pida más preguntas de las que hay
{
	listaTodasPreguntas = leerPreguntas();
	
	int valido;	//si es 1 es válido, si es 0 no lo es.
	int size;

	size = sizeof(listaTodasPreguntas)/sizeof(t_Pregunta_Respuesta);

	if(size < cantPreguntas)
	{
		valido =0;
	}
	else
	{
		valido =1;
	}

	return valido;
}


Pregunta_Respuesta generarPregunta(Pregunta_Respuesta *listaPreguntas) 
{
	//La operación módulo (%) nos da el resto de dividir rand() entre 11. Este resto puede ir de 0 a 10. 
	//De la misma forma, el módulo de rand() entre N+1 va de 0 a N.
	//NO SÉ CUÁNTAS PREGUNTAS TENDREMOS AL FINAL +_+, pero eso sería N

	/*leer el fichero de preguntas y coger 
	una pregunta aleatoria que no esté en la lista 
	que nos pasan y añadir esa nueva pregunta 
	en la lista para que en la siguiente 
	no se genere tampoco esa. 
	Añadirla a la lista después de llamar 
	al método prepararRespuestas(), es decir, 
	con las respuestas ya desordenadas
	*/

	leerPreguntas(listaPreguntas);

	//coger  una pregunta aleatoria que no esté en la lista que nos pasan
	
	//asignarles ún número a cada pregunta en listaTodasPreguntas para que se pueda escoger una aleatorio con el módulo de rand()

	if ()//esa pregunta coincide con preguntas de listaTodasPreguntas)
	{

	}