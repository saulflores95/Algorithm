/*
	Titulo: Listas circulares
	No. de practica: 9
	Alumno: Flores Torres Coto Saul Ivan
	Matricula: 01217102
*/

package main;
import Menu.Menu;
import circularlist.CircularList;

import java.util.Scanner;

public class Main {
	static final Scanner scan = new Scanner(System.in);
	public static CircularList original = new CircularList(); //Inicializacion de patron original
	public static CircularList prueba = new CircularList();  //Inicializacion de patron prueba

	public static void main(String[] args) {
	    String[] menu_opt = {// Creamos arreglo de opciones a menu
	    		"Agregar muestra ADN original.",
	    		"Agregar muestra ADN prueba", 
	    		"Comparar muestras",
	    		"Impresion de ADN",
	    		"Salir"
	    		};
		Menu.titleGen("Listas circulares"); // Se manda llamar funcion que genera titulo
		int sequenceTracker = 2; //Sensor que detecta en que multiplicador va la sequencia
		// se manda a llamar la funcion  generar muno para desplegar y capturar el valor del usuario
		boolean exit = true; //booleano que mantiene el while para generar menu despues de haberlo utilizado
		while(exit) {
			int selectedOption = Menu.generarMenu(menu_opt);  //selecionamos opcion
			switch(selectedOption) {
				case 1: //Primer caso Agregar muestra ADN original
					if(original.size == 0) // Si no se a ingresado datos 
						while(original.size < 4) // la iteracion sucede cuatro veces.
							original.addNodeEnd(); // Se agrega nodo al final de la lista
					else // si ya esta definida se omite
						System.out.println("Lista ya definida");
					break;
				case 2: //Segundo caso Agregar muestra ADN prueba
					if(original.size == 0) { //Si no se a inicializado 
						System.out.println("Ingrese ADN original primero"); //se le pide al usario que inicialize el primer nodo
						break;
					} else if(prueba.size < original.size) { // Si el tamano de prueba es mas chico
						while(prueba.size < original.size) //iterar hasta que tenga el mismo tamano 
							prueba.addNodeEnd(); //agregar la sequencia
					} else { // en el caso que se quiera ampliar la lista PRUEBA
						while(prueba.size < (original.size * sequenceTracker)) //se multiplica el tamano de la sequencia original con el senor detecion de sequencia
							prueba.addNodeEnd(); //se agrega nodos
						sequenceTracker++; //se incrementa sensor de sequencia
					}
					break;
				case 3:
					seqSearch(); //se manda a llamar funcion que compara la sequencias de prueba y original
					break;
				case 4:
					//Impresion de ambas sequencias
					System.out.println();
					System.out.println("Original");
					original.print();
					System.out.println("Prueba");
					prueba.print();
					break;
				case 5:// Cuarto caso salida del programa
					exit = false;
					System.out.println("Bye bye");
					break;
				default: // caso default
					System.out.println("Numero no valido!");
					break;
			}
		}
	
	}

	public static void seqSearch() {
		System.out.println("Init..."); //Inicializacion de comparacion de sequencia
		int i; //Inicializacion de contador para for
		int similarityScore = 0; //Accomuldor de puntaje de similitud
		for(i  = 0; i < prueba.size; i++) { //La iteracion durara la longitud de la lista PRUEBA
			if(original.head.data.equals(prueba.head.data)) { //Si el dato de orginal es el mismo que el dato de prueba
				//Impresion de los datos encontrados similar
				System.out.println("MATHC FOUND: Original: " + original.head.data + " Prueba: " + prueba.head.data);
				//Se continua en ambas lista y se intercambio su tope por el nodo siguente
				original.head = original.head.next;
				prueba.head = prueba.head.next;
				similarityScore++; //Puntuaje de similitud incrementa
			} else {
				//Caso contrario se indica que datos no son similares
				System.out.println("NO SIMILIARITY: Original: " + original.head.data + " Prueba: " + prueba.head.data);				
				//Solo el tope de la lista original cambia el el nodo siguente
				original.head = original.head.next;
			}
		}
		//Terminada la iteracion se imprime el score de similitud y de tamano de prueba
		System.out.println("SimilarityScore: " + similarityScore);
		System.out.println("Size of test: " + prueba.size);
		//Se obtiene porcentaje de similitud
		float percent = (similarityScore * 100.0f) / prueba.size;
		//Despligue en pantalla
		System.out.println(percent + "% similar");
	}
}
