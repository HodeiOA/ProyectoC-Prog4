//#include "jugador.h"
//#include "Pregunta_Respuesta.h"
#include "INCLUDES/utilidades.h"
#include <string.h>
//#include <stdio.h>
#include <time.h> //para random
//Declaración de métodos
void menuAdmin();
void menuJugador();
void individual();
void multijugador();
void ranking();
void acabar();

//Listas de Jugadores y preguntas que hayan ido saliendo
t_jugador* jugadores;
t_pregunta_respuestas* preguntasSalidas;

//Si tras estos intentos de encontrar una pregunta que no haya salido aún no se consigue, se mostrará una aleatoria, sin importar si está repetida
int MAX_INTENTOS=20 ;

int main(int argc, char** argv)
{
	//-----------Decidir si es un jugador o es un administrador
	//es un administrador  
  if (argc==2)
  {
  	//Para comparar los strings, usamos strcmp
	int admin;
	admin=strcmp(argv[1],"admin");

		if (admin==0)
		{
			menuAdmin();
		}	
  }
  else //es un jugador
  {
  	//Antes de mostrar el menú, como es la primera vez, hacemos que se identifique
  	char* nick;
  	recogerNick(&nick);
    menuJugador();
    //asignarle nick al jugador
  }

  return 0;
}

 void menuAdmin()
 {
 	 mostrarMensaje("Hola, administrador\n"); 

  	//Todo irá dentro de un do-while, ya que al menos una vez se realizará y según lo el valor que le dé a la variable "opción" saldrá o no del bucle
  	int opcion=0;

   do
  	{
	  	int cant_p;//cantidad de preguntas que va a insertar el administrador
	  	int MAX_PREG = 250;
	  	int MAX_RESP = 200;

		mostrarMensaje("Indica la cantidad de preguntas que deseas introducir:  ");
	    recogerInt(&cant_p); //en recoger int, añadir mensajes de error si no es un int
	   
	    while(cant_p<=0)
	    {
	    	mostrarMensaje("El número de preguntas debe ser superior a 0. Por favor, inténtalo de nuevo: \n");
	    	recogerInt(&cant_p); 
	    }

	    t_pregunta_respuestas preg_r[cant_p]; //array de preguntas_respuestas

	    for (int i=0; i<cant_p; i++)
	    {
	    	 char* pregunta;
	    	 char* r1;
	    	 char* correcta;//variable auxiliar para guardar la respuesta correcta con un punto por delante en la structura
	    	 char* r2;
	    	 char* r3;

	    	mostrarMensaje("Introduce la pregunta a insertar: ");
	    	recogerString(&pregunta, MAX_PREG);

	    		
	    	 mostrarMensaje("\n*La respuesta no debe contener la letra de la opción (a, b, c) ni signos de puntuación al inicio (salvo que se trate de un guión, por ser la respuesta un número negativo)");
	    	 mostrarMensaje("\nIntroduce la respuesta correcta: ");
	    	 recogerString(&correcta, MAX_RESP);

	    	 //Hacemos un malloc para que el array tenga tandos caracteres como la respuesta correcta +1, para el punto y para el \0
	    	 r1=(char*)malloc(strlen(correcta+2)*sizeof(char*));

	    	 r1[0]='.'; //Le ponemos a r1 el .
	    	 r1[1]=0; //Para convertir la cadena de caracteres en String, le ponemos el 0 (o \0)
	    	 //Ponerle el punto delante a la respuesta correcta
	    	 strcat(r1,correcta); 
	    	 
	    	 mostrarMensaje("\nIntroduce otra respuesta (una incorrecta): ");
	    	 recogerString(&r2, MAX_RESP);
	    	 mostrarMensaje("\nIntroduce otra respuesta (una incorrecta): ");
	    	 recogerString(&r3, MAX_RESP);

	    	 preg_r[i].Pregunta = pregunta;
	    	 preg_r[i].Respuesta1 = r1;
	    	 preg_r[i].Respuesta2 = r2;
	    	 preg_r[i].Respuesta3 = r3;

	    	 free(r1);
	    	 r1=NULL;
	    }

	    mostrarMensaje("\n¿Quieres seguir introduciendo preguntas?\n");
 		mostrarMensaje("\t1.- Sí\n");
 		mostrarMensaje("\t2.- No\n");
 		recogerInt(&opcion);

	}while (opcion!=2);

 }

 void menuJugador()
 {
 	int opcion;

 	 mostrarMensaje("----MENÚ----\n"); 
 	 mostrarMensaje("Por favor, elije una de las siguientes opciones:\n"); 
 	 mostrarMensaje("\t 1.- Jugar partida individual\n"); 
 	 mostrarMensaje("\t 2.- Jugar partida multihugador\n"); 
 	 mostrarMensaje("\t 3.- Ver ránking\n"); 
 	 mostrarMensaje("\t 4.- Salir \n"); 
 	 mostrarMensaje("Indica el número de la opción que quieres elegir\n"); 
 
  	recogerInt (&opcion);

	while(!(opcion>0 && opcion<5))
  	{
  		mostrarMensaje("Opción no válida. Por favor, indica el número de la opción que quieres elegir\n"); 
  		recogerInt (&opcion);
  	}

  	switch(opcion)
  	{
  		case 1: 
  		mostrarMensaje("Has elegido la opción número 1: Jugar partida individual \n"); 
  		individual();
  		break;

  		case 2:
  		mostrarMensaje("Has elegido la opción número 2: Jugar partida multijugador \n"); 
  		multijugador();
  		break;

  		case 3:
  		mostrarMensaje("Has elegido la opción número 3: Ver ránking\n"); 
  		ranking();
  		break;

  		case 4:
  		mostrarMensaje("Gracias por jugar ¡Vuelve pronto!\n"); 
  		acabar();
  		exit(0);

  		break;

  		default:
  		break;
  	}
 }

 void individual()
 {
 	unsigned int cant_preguntas;
 	int max_preguntas;//Leer las preguntas, meterlas en un array y contar la cantidad de posiciones de ese array
 	t_pregunta_respuestas* arrPreg; //todas las preguntas guardadas en el fichero
 	t_pregunta_respuestas* aux; //Este es un array auxiliar para poder ir añadiendo las preguntas que vayan saliendo
 	t_pregunta_respuestas pregunta;
 	int random;//variable en la que guardaremos el número aleatorio para elegir una pregunta aleatoria
 	int repetida = 0; //Variable para ver si en cada momento la pregunta elegida aleatoriamente es i no alguna que ya ha salido
 	int sizePreguntasSalidas;
 	int sizeTotalPreguntas;
	
 	int cont=0;
 	int respValida=-1;
 	char respuesta;

 	//Leer todas las preguntas
 		//Llamar a data
 	//Cantidad de preguntas en cada array
 	sizePreguntasSalidas = sizeof(preguntasSalidas)/sizeof(t_pregunta_respuestas);
 	sizeTotalPreguntas = sizeof(arrPregRes)/sizeof(t_pregunta_respuestas);

 	mostrarMensaje("\t Juego individual");
 	mostrarMensaje("¿Cuántas preguntas deseas que se te realicen?\t");
 	recogerInt(&cant_preguntas);
 	
 	while(cant_preguntas<0 || cant_preguntas> max_preguntas)
 	{
		mostrarMensaje("El número de preguntas no es válido (porque es muy elevado o porque no es mayor a 0)\n Por favor, introduce otro número: \t");
 		recogerInt(&cant_preguntas);
 	}

 	srand(time(NULL));
 	for (int i = 0; i < cant_preguntas; ++i)
	 {
	 	do
	 	{
		 		random = rand() %(cant_preguntas); //genera un número aleatorio entre 0 y cant_preguntas-1
		 		pregunta = arrPregR[random];

		 		for(int j=0; j < sizePreguntasSalidas; i++)
		 		{
		 			repetida = strcmp (pregunta.Pregunta,preguntasSalidas[i].Pregunta); //si son iguales, será 0
		 		}
		 	
		 	cont++;
	 	}while(repetida==0 || cont !=MAX_INTENTOS) //Hará esto hasta que encuentre una pregunta no repetida o agote la cantidad de intentos
	 
	 aux = (t_pregunta_respuestas*) malloc (sizeof(t_pregunta_respuestas)*sizePreguntasSalidas+1);//creamos espacio para las preguntas ya salidas +1 (la nueva)
	//metemos todas las preguntas del array de los ya salidos en la variable auxiliar
	 for (int i=0; i<sizePreguntasSalidas; i++)
	 {
	 	aux[i] = preguntasSalidas [i];
	 }
	 aux[sizePreguntasSalidas] = pregunta;//Añadimos la pregunta en la variable auxiliar

	 //Hacemos malloc de preguntasSalidas otra vez para darles espacio para un hueco más
	 preguntasSalidas = (t_pregunta_respuestas*) malloc (sizeof(t_pregunta_respuestas)*sizePreguntasSalidas+1);
	 for (int i=0; i<sizePreguntasSalidas+1; i++)
	 {
	 	preguntasSalidas [i] = aux[i]; 
	 }
	 //nos libramos de aux porque ya no nos hace falta
	 free(aux);
	 aux = NULL;

	 mostrarPregunta(pregunta);
	 mostrarRespuestas(pregunta);
	 respValida = recogerRespuesta(&respuesta);

	 while(respValida == -1)
	 {
	 	 respValida = recogerRespuesta(&respuesta);
	 }

	 //LLAMAR AL MÉTODO DE OPERACIONES QUE COMPRUEBA SI LA RESPUESTA ES CORRECTA O NO


	 }
 }

 void multijugador()
 {

 }

 void ranking()
 {

 }

 void acabar()//método para liberar recursos
 {
 	free(preguntasSalidas);
 	preguntasSalidas = NULL;
 	free(jugadores);
 	jugadores = NULL;
 }