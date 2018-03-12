/*
 	Titulo: Recursividad
 	No. de practica: 3
 	Descripcion: Juego de buscaminas recursivo de 16 renglones y 9 columnas.
 	Alumno: Flores Torres Coto Saul Ivan
 	Matricula: 01217102
*/
import java.util.Scanner;

public class Main {
	static Matriz mat = new Matriz(16, 9); //	matriz que contiene los datos del juego
	static Matriz fakeMat = new Matriz(16, 9);//	matriz que esconde todos los valores

	public static void main(String[] args) {
		int x, y; //	Se declaran variables que el usario va a modifcar
		Boolean bol = new Boolean(true);	// se inicializa tipo booleano para generar in while loop
		Scanner scan = new Scanner(System.in); // scanner para obtener datos de tipo int del usuario
		String evaluatedVar;	//	valor a evaluar de matriz
		fakeMat.fillFakeMatrix(); //	Llenar matriz de x para efectos de visualizacion
		fakeMat.printMatrix(); //impresion de matriz vacia
		mat.fillMatrix(); // generar datos random para matriz
		while(bol) { //	loop para mantener el juego andando
			System.out.println("Ingrese la cordenada x:"); 
			x = scan.nextInt();	//	captura de valor de usario
			if(x > mat.ren) { //	verficiar que no se haya exedido
				System.out.println("Valor excedido seleciona una cordenada menor a " + mat.ren);
				x = scan.nextInt();	// recaptura de valor de usario
			}
			System.out.println("Ingrese la cordenada y:");
			y = scan.nextInt(); //	captura de valor de usario
			if(y > mat.col) {
				System.out.println("Valor excedido seleciona una cordenada menor a " + mat.col);
				y = scan.nextInt();		// recaptura de valor de usario		
			}
			evaluatedVar = mat.getSelectedValue(x, y); //valor a evaluar
			verificarCeros(x, y);	//verficador de ceros vecinos recursivo
			if(evaluatedVar == "#") { //si sale gato loop termina
				bol = false;	//se cambia booleano para terminar el loop
				fakeMat.contentArray[x][y] = mat.contentArray[x][y]; //se iguala el gato a la matriz a desplegar
				System.out.println("Perdiste :'(");
				scan.close(); //se cierra el scan para evitar overflows
			}
			fakeMat.printMatrix(); //se imprime matriz a desplegar
		}
	}
	//	funcion recursiva
	public static void verificarCeros(int x, int y) {
		if(x < 0 || x > mat.ren - 1 || y < 0 || y > mat.col - 1) {
			return; //primer caso base verifica rango de datos que ingreso usuario
		}else if(fakeMat.contentArray[x][y] == "0") { 
			return; //segundo caso base verifica si la posicion ya fue activada
		}else if(mat.contentArray[x][y] == "#") { 
			return; //tercer caso base verifica que sea gato cortar la recursividad
		}else if(mat.contentArray[x][y] == "0") { //
			fakeMat.contentArray[x][y] = mat.contentArray[x][y];// se iguala valores de matriz real a matriz a desplegar
			//Evaluacion de todos los posibles vecinos a la posicion actual
			verificarCeros(x-1,y-1);
			verificarCeros(x-1,y);
			verificarCeros(x-1,y+1);
			verificarCeros(x,y-1);
			verificarCeros(x,y+1);
			verificarCeros(x+1,y-1);
			verificarCeros(x+1,y);
			verificarCeros(x+1,y+1);		
		} else { //cualquier otro caso que no se alla presentado sera salido
			return;
		}
	}
}


