/*
	Titulo: Listas Doblemente Enlazadas
	No. de practica: 8
	Alumno: Flores Torres Coto Saul Ivan
	Matricula: 01217102
*/

package main;

import Menu.Menu;
import doublelinkedlists.DoubleLinkedList;
import doublelinkedlists.DoubleLinkedList.Node;
import java.util.Scanner;

public class Main {
	
	public static DoubleLinkedList medicamentos;
    static final Scanner scan = new Scanner(System.in);

	public static void main(String[] args) {
		medicamentos = new DoubleLinkedList(); //Inicializamos nuestro objeto de contenedor de los medicamentos inicializados
	    String[] menu_opt = {// Creamos arreglo de opciones a menu
	    		"Agregar medicamento nuevo.",
	    		"Eliminar medicamento", 
	    		"Mostrar productos ordenados por alfabéticament",
	    		"Mostrar productos ordenados por fecha de vencimiento ascendente",
	    		"Salir"
	    		};
		Menu.titleGen("Listas Doblemente Enlazadas"); // Se manda llamar funcion que genera titulo
		// se manda a llamar la funcion  generar muno para desplegar y capturar el valor del usuario
		boolean exit = true; //booleano que mantiene el while para generar menu despues de haberlo utilizado
		while(exit) {
			int selectedOption = Menu.generarMenu(menu_opt);  //selecionamos opcion
			switch(selectedOption) {
				case 1: //Agregar medicamento nuevo.
					System.out.println();
					Node newMed = medicamentos.createNode(); //Creamos nodo
					medicamentos.sortedInsert(newMed);	//Ingresamos nodo en orden alfabetico
					break;
				case 2: // Eliminar medicamento
					System.out.println();
					System.out.println("Eliminar medicamento");
					String nameToDelete = scan.nextLine(); //Capturamos medicina a eliminar
					medicamentos.removeNode(medicamentos.head, nameToDelete); //mandamos a llamar metodo para eliminar nodo
					break;
				case 3: // Mostrar productos ordenados por alfabéticament
					System.out.println();
					System.out.println("Mostrar productos ordenados por alfabéticamente");
					medicamentos.printList(medicamentos.head);
					break;
				case 4: // **NO SE TERMINO **Mostrar productos ordenados por fecha de vencimiento ascendente
					System.out.println();
					System.out.println("Mostrar productos ordenados por fecha de vencimiento ascendente");
					System.out.println("FUNCION NO TERMINDA. COMING SOON... :(");
					break;
				case 5:// Caso cinco salida del programa
					exit = false;
					System.out.println("Bye bye");
					break;
				default: // caso default
					System.out.println("Numero no valido!");
					break;
			}
		}
	
	}

}
