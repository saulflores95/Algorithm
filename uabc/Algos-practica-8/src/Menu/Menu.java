package Menu;

import java.util.Scanner;

public class Menu {
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
	public static void titleGen(String title) {
		System.out.println("****************************************************************");
		System.out.println("*******************" + title +"******************");
		System.out.println("****************************************************************");	
	}
}
