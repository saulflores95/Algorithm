
public class Polinomio {
	private int polDegree;//	grado de polinomio
	public int polSize;//		tamano real de polinomio
	private int[] polArr;//		contenido de polinomio
	private int top = 0;//		tope del arreglo
	private int back = -1;//	parte inferior del arreglo
	public int currentSize = 0;//	tamano actual del arreglo
	//	Constructor
	public Polinomio(int degree) {
		this.polDegree = degree;	//	Se declara el grado de polinomio
		this.polSize = polDegree*2; //  de termina el tamano del arreglo
		this.polArr = new int[polSize];	//	Se inicializa la cola dinamica	
	}
	//	Funcion que agrega contenido a la cola
    public void enqueue(int val) {  
        if (isPolFull()) {	// Si la cola esta llena
            System.out.println("Cola llena se incrementara tamano"); 
            incPolDegree();// se incrementa el tamano de la cola
        }
        back++; //La parte inferor de la cola se incrementa
        if(back >= polArr.length && currentSize != polArr.length){
            back = 0; //Si la parte inferior es igual o mayor al tamano del arreglo se restablece su valor a 0
            //No se restablece a menos uno porque NO  esta vacia
        }
        polArr[back] = val; //Al final de la cola si ingresa el nuevo valor
        currentSize++; // se icnrementa tamano de cola
        System.out.println("Agregando: " + val);
    }
	// funcion que elimina primer contenido en la cola
    public void dequeue() {
        if (isPolEmpty()) { // SI la cola esta llena no se puede eliminar
            System.out.println("Cola vacia ! No se puede eliminar...");
        } else {
            top++; // el tope se incrementa
            if(top > polArr.length-1){ // si el tope es mayor al tamano de arreglo
                System.out.println("Eliminando: "+polArr[top-1]); // se decrementa el tope
                top = 0; //tope se iguala a 0
            } else {
                System.out.println("Eliminando: "+polArr[top-1]); // se decremta tope
            }
            currentSize--; // Se decremental el tamano del la cola
        }
    }
	//	funcion que grado de polinomio
	public void incPolDegree() {
        int newCapacity = this.polArr.length*2;
        int[] newArr = new int[newCapacity];
        int tmpTop = top;
        int i = -1;
        while(true){
            newArr[++i] = this.polArr[tmpTop];
            tmpTop++;
            if(tmpTop == this.polArr.length){
            	tmpTop = 0;
            }
            if(currentSize == i+1){
                break;
            }
        }
        this.polArr = newArr;
        System.out.println("El tamano de la cola nueva: "+this.polArr.length);
        this.top = 0;
        this.back = i;
	}
	// funcion que verifica si polinomio/cola esta vacio
	public boolean isPolEmpty() {
		return currentSize == 0;
	}
	// funcion que verifica si polinomio/cola esta llena
	public boolean isPolFull() {
		return currentSize == polArr.length;
	}
	// funcion que imprime polinomio
	public void printPol() {
		StringBuilder poliString = new StringBuilder();
		poliString.append("");
		for(int i = 0; i < polArr.length; i++) {
			if(i == 0) {
				poliString.append(String.valueOf(polArr[i]));
			}
			else if(i == polArr.length - 1) {
				poliString.append("x^");
				poliString.append(String.valueOf(polArr[i]));
			}
			else if(i > 0 && (i % 2) != 0) {
				poliString.append("x^");
				poliString.append(String.valueOf(polArr[i]));
				poliString.append(" + ");
			}
			else {
				poliString.append(String.valueOf(polArr[i]));		
			}
		}
		System.out.println("Su polinomio: ");
		System.out.println(poliString);
	}
	// funcion que evalua polinomio
	public void polEval(double x) {
		double ans = 0; // Valor de la evaluacion inicializado
		for(int i = 0; i < polArr.length - 1; i++) { //Se itera los valores y se inicio con el grado mas grande
			double val = polArr[i]; //valor inicial
			double exp = Math.pow(x, (polArr[i++] - 1)); //valor que se eleva a un exponente
			double multi = val * exp; // multipliacion de los valores
			ans += multi;	//se le suma al valor de ans la respuesta multiplicadoa
		}
		System.out.println("P(" + x +") = "  + ans); //impresion de resuultado
	}
}
