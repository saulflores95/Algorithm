import java.util.*;
/*
 	Titulo: Operaciones con numeros complejos
 	No. de practica: 1
 	Alumno: Flores Torres Coto Saul Ivan
 	Matricula: 01217102
*/
public class Aritmetica {
	private static Scanner scan;
	//Funcion generadora de menu
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
	//Generador de titulo
	public static void titleGen() {
		System.out.println("***********************************************");
		System.out.println("*******Operaciones con numeros Complejos*******");
		System.out.println("***********************************************");
	}
	
	//Funcion aritmetica de tipo suma para numeros complejos
	public static Complejo addComplex(Complejo complexA, Complejo complexB) {
		complexA.x += complexB.x;
		complexA.y += complexB.y;
		return complexA;
	}
	
	//Funcion aritmetica de tipo resta para numeros complejos
	public static Complejo subComplex(Complejo complexA, Complejo complexB) {
		complexA.x -= complexB.x;
		complexA.y -= complexB.y;
		return complexA;
	}
	
	//Funcion aritmetica de tipo  multiplicacion para numeros complejos
	public static Complejo multiCompleX(Complejo complexA, Complejo complexB) {
		complexA.r *= complexB.r;
		complexA.theta += complexB.theta;
		return complexA;
	}
	
	//Funcion aritmetica de tipo division para numeros complejos
	public static Complejo devideComplex(Complejo complexA, Complejo complexB) {
		complexA.r /= complexB.r;
		complexA.theta -= complexB.theta;
		return complexA;
	}
	
	public static void main (String[] args) {
		titleGen(); //generador de titulo
		double xOne,yOne, xTwo, yTwo; //se declaran los valors que generaran los numeros complejos
		int optionSelect; //se declara variable que determina que opcion se va a utilizar
		boolean exit = true; //booleano que mantiene el while para generar menu despues de haberlo utilizado
		Complejo complejoAns; //valor complejo que se retorna despues de una operacion
		scan = new Scanner( System.in );
		//Array de strings que conforma el menu
		String[] menuOpciones = new String[] {
    		"Suma de dos n�meros complejos.", 
    		"Resta de dos n�meros complejos.",
    		"Multiplicaci�n de dos n�meros complejos.",
    		"Divisi�n de dos n�meros complejos.",
    		"Salir"
		};
   
		//Captura de datos que forma numero complejo Uno
		System.out.print("Ingrese x1:");
		xOne = scan.nextDouble();
		System.out.print("Ingrese y1:");
		yOne = scan.nextDouble();
		Complejo complejoUno = new Complejo(xOne, yOne);
		complejoUno.printComplex();
		
		//Captura de datos que forma numero complejo Dos
		System.out.print("Ingrese x2:");
		xTwo = scan.nextDouble();
		System.out.print("Ingrese y2:");
		yTwo = scan.nextDouble();
		Complejo complejoDos = new Complejo(xTwo, yTwo);
		complejoDos.printComplex();	   
		//Loop tipo while para mantener el menu despues de ser utilizado
		while(exit) {
			optionSelect = generarMenu(menuOpciones);
			switch(optionSelect) {
				case 1: 
						complejoAns = addComplex(complejoUno, complejoDos);
						complejoAns.printComplex();
						break;
				case 2: 
						complejoAns = subComplex(complejoUno, complejoDos);
						complejoAns.printComplex();
						break;		
				case 3: 
						complejoAns = multiCompleX(complejoUno, complejoDos);
						complejoAns.printPolar();
						break;
				case 4: 
						complejoAns = devideComplex(complejoUno, complejoDos);
						complejoAns.printPolar();
						break;
				case 5:
						System.out.print("Adios que tenga bonito dia");
						exit = false;
						break;
				default: 
						System.out.println("Numero no valido!");
						break;
			}
		}
	}
	 
} 
