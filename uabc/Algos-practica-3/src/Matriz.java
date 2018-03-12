import java.util.Random;

public class Matriz {
	//Variables inicializdoes
	int ren; //	Tamano de renglon
	int col; // Tamano de columna
	String[][] contentArray; // Arreglo de contenido de matriz
	//	Constructor de matriz
	public Matriz(int ren, int col) {
		this.ren = ren; //	Se igualan los valores del constructor
		this.col = col; //	Se igualan los valores del constructor
		contentArray = new String[ren][col];
	}
	//	Funcion que llena los datos de la matriz
	public void fillMatrix() {
		int i, j, //	Se declaran variables iteradoras
			min, max, //	Se declaran los rangos de numeros alateorios que se van a generar
			range, randomNum; //	Se decalra el rango y el valor aleatorio
		Random ran = new Random(); //	Se inicializa una objecto tipo Random
		min = 1; //	Se declara el valor minimio del rango que es 1 
		max = 3; // Se declara el valor maximo del rango que es 3
		range = max - min + 1; //	se calcula el rango donde vamos a generar valores aleatorios
		for(i = 0; i < ren; i++) {	//	Se itera los renglones
			for(j = 0; j < col; j++) {	//Se itera las columnas
				randomNum = ran.nextInt(range) + 1; //Se generar un numero aleatorio
				if(randomNum == 1) { // Si el numero aletaorio es 1 se le agrega una bomba
					contentArray[i][j] = "#";
				} else { // Si el numero es cualquier otro valor se le agrega un 0 al arreglo
					contentArray[i][j] = "0";
				}
			}
		}
	}
	public void fillFakeMatrix() {
		int i, j; //	Se declaran variables iteradoras
		for(i = 0; i < ren; i++) {	//	Se itera los renglones
			for(j = 0; j < col; j++) {	//Se itera las columnas
				contentArray[i][j] = "x";
			}
		}
	}
	//	Funcion que imprime contenido de matriz
	public void printMatrix(){
	    try{
	        String str = "|\t"; // Genera espacio para acomodar
	        for(int k = 0; k < col; k++) {	//	ciclo que genera el contador de columnas
	        	System.out.print("\t" + k); //	impresion de contador de columnas en la parte superior de la matriz
	        }
	        System.out.println();// Impresion de linea vacia para no lastimar la impresion del contenido de la matriz
	        for(int i = 0;i < ren; i++){ // iteracion sobre renglones
	            for(int j = 0; j < col; j++){ //iteracion sobre columnas
	                str += contentArray[i][j] + "\t"; // se concatena el contenido del arreglo con el espacio
	            }
	            System.out.println(str + "|" + i); // Se agrega linea final con numero de renglon
	            str = "|\t";	//Se regresa valor de str a su estado original
	        }

	    }catch(Exception e){System.out.println("Matriz vacia");}
	}
	// Funcion que regresa valor obtenido
	public String getSelectedValue(int i, int j) {
		return contentArray[i][j];
	}
}
