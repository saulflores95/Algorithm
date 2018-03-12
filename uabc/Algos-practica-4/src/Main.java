import java.util.Scanner;

/*
 	Titulo: 
 	No. de practica: 4
 	Alumno: Flores Torres Coto Saul Ivan
 	Matricula: 01217102
*/
public class Main {
	private static Scanner scan; //	declaracion global de scan
	static Polinomio pol = new Polinomio(3);// declaracion global de polinomio con el grado default siendo un polinomio
											// De tercer grado
	//	Funcion generadora de menu
	public static int generarMenu(String[] arr_opt) {
		  int i, menuValue;
		  System.out.println("\n");
		  for(i = 0; i < arr_opt.length; i++) {
			  System.out.println((i+1) + " " + arr_opt[i]);
		  }
		  System.out.print("Ingrese el numero de la opcion:");
		  scan = new Scanner( System.in );
		  menuValue = scan.nextInt();
		  return menuValue;
	  } 
	//	Generador de titulo
	public static void titleGen(String title) {
		System.out.println("***********************************************");
		System.out.println("****************"+ title + "****************");
		System.out.println("***********************************************");
	}
	//	Controlador de logica contenida en menu
	public static void logicaMenu() throws Exception {
		int optionSelect; //se declara variable que determina que opcion se va a utilizar
		boolean exit = true; //booleano que mantiene el while para generar menu despues de haberlo utilizado
		scan = new Scanner( System.in );
		//Array de strings que conforma el menu
		String[] menuOpciones = new String[] {
			"Capturar término en el orden que corresponda.",
			"Ver polinomio.",
			"Evaluar polinomio.",
			"Eliminar el primer término.",
    		"Salir"
		};
		while(exit) {
			optionSelect = generarMenu(menuOpciones); //	generar menu
			switch(optionSelect) {
				case 1: //	Caso 1 captura de terminos
						int val; // valor donde se captura inicializado
						if(pol.isPolFull()) //	Si el polinomo ya esta lleno
							pol.incPolDegree();	// Se incrementa tamano de polinomio
						else {
							while(!pol.isPolFull()) { // Si el polinomio no esta lleno ciclo hasta llenar
								System.out.print("Introduzca un número"); 
								val = scan.nextInt();// Se caputa dato en variable val
								pol.enqueue(val);	// Se ingresa dato a cola
							}
						}
						break;
				case 2:
						if(pol.isPolEmpty()) // Si el polinomio esta vacio se  imprime vacio
							System.out.println("Polinomio vacio");					
						else
							pol.printPol(); // Impresion de polinomio
						break;
				case 3: // Caso tres evaluacion de polinomio
						double x;
						System.out.println("Evaluando...");
						System.out.print("Introduzca un el valor de x"); 
						x = scan.nextInt();// Se caputa dato en variable x
						pol.polEval(x);
						break;
				case 4: //caso 4 elimnar primer valor
					if(pol.isPolEmpty()) // Si polinomio esta vacio se le indica al usario
						System.out.println("Polinomio vacio");
					else {
						if(pol.polSize % 2 == 0) { // Si posicion del polinomio es un termino primo se selimina dos
							pol.dequeue();
							pol.dequeue();
						}else { //prueba unitaria para verificion de funcionamiento de colas
							System.out.println("This should not happen.. Check on dequeue menu");
							pol.dequeue();
						}
					}
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
	//	Funcion main del programa
	public static void main(String[] args) throws Exception {
		titleGen("Estructura FIFO"); //generador de titulo
		logicaMenu();// Se manda a llamar la logica del menu
	}
}
