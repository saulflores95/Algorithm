import java.util.*;
/*
 	Titulo: Estructuras LIFO Estáticas
 	No. de practica: 2
 	Alumno: Flores Torres Coto Saul Ivan
 	Matricula: 01217102
*/

public class Pilas {
	//Funcion verificadora de contenido de string
	public static boolean Verificador(String valueToCheck) { //se recive parametro string que contiene la expression
        Stack<Character> st  = new Stack<Character>(); //se inicializa un stack  de tipo char
		int i; // inicializado valor iterador
		for(i = 0; i < valueToCheck.length(); i++) { //se ejecuta ciclo for utilizando la longitud del String
			char indChar = valueToCheck.charAt(i); //se inicializa indiChar(char individual) y se extrae el valor del string correspondiente al indice y se convierte en char
			if(indChar == '(' || indChar == '{' || indChar == '[') { // se verifica que el valor inicial de la expression que contenga ( [ { se agregue el stack
				st.push(indChar); //se agrega el valor indicado al stack de caracteres llamado st
		    } else if(indChar == ']') { //si no es el caso previo  se compara que se un corchete cerrado
		        if(st.isEmpty() || st.pop() != '[') { //si es el caso del cerrado hace una decicion dependiendo si el stack esta vacio o el ultimmo valor sea uno abierto
		            return false; // si esta condicion se cumple sabemos que la expression no es correcta
		        }
		    } else if(indChar == ')') { //si no es el caso previo, la condicional espera que sea un parentesis cerrado
		        if(st.isEmpty() || st.pop() != '(') { //si es el caso del cerrado hace una decicion dependiendo si el stack esta vacio o el ultimmo valor sea uno abierto
		            return false; // si esta condicion se cumple sabemos que la expression no es correcta
		        }           
		    } else if(indChar == '}') { //si no es el caso previo, la condicional espera que sea un parentesis cerrado
		        if(st.isEmpty() || st.pop() != '{') { //si es el caso del cerrado, hace una decicion dependiendo si el stack esta vacio o el ultimmo valor sea uno abierto
		            return false; // si esta condicion se cumple sabemos que la expression no es correcta
		        }
		    }
		
		}
		return st.isEmpty(); // si el array is vacio se regresa un un booleano
	}
	
	public static void main (String[] args) {
		String testString = "1 + 3 + { {1 - 4  }"; //String de prueba
		boolean test = Verificador(testString); //llamada de prueba
	    Scanner scan = new Scanner(System.in); //se incializa el scanner de variables
	    System.out.print("Ingresa una expression: "); 
	    String expresion = scan.nextLine(); // se captura expression
		if(Verificador(expresion)) { // Si valor es verdadero la expression si funciona
			System.out.println("Expression es valida");
		} else {
			System.out.println("Expression NO es valida");
		}
	}
}
