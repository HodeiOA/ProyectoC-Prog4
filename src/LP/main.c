//#include "jugador.h"
#include "utilidades.h"
//#include "operaciones.h"
//#include "preguntas_respuestas.h"
//#include "data.h"
#include <string.h>
//Declaración de métodos
void menuAdmin();
void menuJugador();

int main(int argc, char** argv)
{
	//Para comparar los strings, usamos strcmp
	int admin;
	admin=strcmp(argv[1],"admin");
	//-----------Decidir si es un jugador o es un administrador
	//es un administrador
  if (argc==2 && admin==0)
  {
  			menuAdmin();
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
 	 mostratMensaje("Hola, administrador\n"); 
 	/*
  	//Todo irá dentro de un do-while, ya que al menos una vez se realizará y según lo el valor que le dé a la variable "opción" saldrá o no del bucle
  	int opcion;
  	do
  	{
	  	int cant_p;//cantidad de preguntas que va a insertar el administrador
	  	t_pregunta_respuestas preg_r;

	    mostrarMensaje("Indica la cantidad de preguntas que deseas introducir");
	    recogerInt(&cant_p); //en recoger int, añadir mensajes de error si no es un int
	    while(cant_p<0)
	    {
	    	mostrarMensaje("El número de preguntas debe ser un número natural. Por favor, inténtalo de nuevo: \n");
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
	    	 recogerString(&pregunta);
	    	 mostrarMensaje("\n*La respuesta no debe contener la letra de la opción (a, b, c) ni signos de puntuación al inicio (salvo que se trate de un guión, por ser la respuesta un número negativo)");
	    	 mostrarMensaje("\nIntroduce la respuesta correcta: ");
	    	 recogerString(&correcta);

	    	 //Hacemos un malloc para que el array tenga tandos caracteres como la respuesta correcta +2, uno para el punto y otro para \0
	    	 r1=(char*)malloc(strlen(correcta+2)*sizeof(char*));

	    	 r1[0]=".";//Como es la respuesta correcta, la guardamos con un punto por delante
	    	//Para guardar el resto de la respuesta, recorremos el string carácter a carácter y lo guardamos en r1
		    	 for(int j=0; j<strlen(correcta); j++)
		    	 {
		    	 	r[j+1]=correcta[j];
		    	 }
		    r1[strlen(correcta)+1]=\0;

	    	 mostrarMensaje("\nIntroduce otra respuesta (una incorrecta): ");
	    	 recogerString(&r2);
	    	 mostrarMensaje("\nIntroduce otra respuesta (una incorrecta): ");
	    	 recogerString(&r3);

	    	 preg_r[i].Pregunta = pregunta;
	    	 preg_r[i].Respuesta1 = r1
	    	 preg_r[i].Respuesta2 = r2;
	    	 preg_r[i].Respuesta3 = r3;
	    }

	    mostrarMensaje("\n¿Quieres seguir introduciendo preguntas?\n");
 		mostrarMensaje("\t1.- Sí\n");
 		mostrarMensaje("\t2.- No\n");
 		recogerInt(&opcion);

    }while (opcion!=2);
*/
 }

 void menuJugador()
 {
  
 }