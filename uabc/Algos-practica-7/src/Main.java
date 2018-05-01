import java.util.Scanner;

import LinkedList.LinkedList;
import Menu.Menu;
/*
	Titulo: Listas Enlazadas
	No. de practica: 7
	Alumno: Flores Torres Coto Saul Ivan
	Matricula: 01217102
*/
public class Main {

	private static Scanner scan;

	public static void main(String[] args) {
		// Generamos arreglo de las opciones que se agregaran al objeto menu
	    String[] menu_opt = {
	    		"Agregar una palabra al final de la lista",
	    		"Insertar una palabara en la lista", 
	    		"Eliminar una palabara",
	    		"Reproducir lista",
	    		"Salir"
	    		};
		Menu.titleGen("Listas Enlazadas"); // Se manda llamar funcion que genera titulo
		// se manda a llamar la funcion  generar muno para desplegar y capturar el valor del usuario
		boolean exit = true; //booleano que mantiene el while para generar menu despues de haberlo utilizado
		LinkedList list = new LinkedList(); //Generamos objeto tipo lista enlazada
	    scan = new Scanner(System.in);
		while(exit) {
			int selectedOption = Menu.generarMenu(menu_opt); 
			switch(selectedOption) {
				case 1: //caso uno agregar a final de lista
					System.out.println("Agregar una palabra al final de la lista");
				    System.out.print("Ingresa el dato: ");
				    String dato = scan.nextLine();
				    list.addToEnd(dato);
					break;
				case 2: // Caso dos insertar despues de palabra 
					System.out.println("Insertar una palabara en la lista");
				    System.out.print("Ingresa el dato: ");
				    String data = scan.nextLine();
				    System.out.println("Ingresa el valor previo a ingresar: ");
				    String afterOf = scan.nextLine();
				    list.insertAfter(data, afterOf);
					break;
				case 3: // Caso tres eliminar lista
					System.out.println("Eliminar una palabara");
				    System.out.print("Ingresa el valor que desea eliminar: ");
				    String dataToRemove = scan.nextLine();
				    list.remove(dataToRemove);
					break;
				case 4: // Caso cuatro Reproducir lista
					System.out.println("Reproducir lista");
					list.printList();
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
