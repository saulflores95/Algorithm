package circularlist;

import java.util.Scanner;

public class CircularList {
	public int size = 0; //tamano de la lista
	public Node head = null; //Tope de lista
	public Node tail = null; //Cola de lista
	Scanner scan = new Scanner(System.in);
	//Funcion que captura base de ADN con uso de exprecion regular "[ATGC]"
	public String captureChar() {
		System.out.println("Agrega base de ADN: A, T, G o C");
		//Para poder salir de siclo se necesita agregar los valores acceptados
		while(!scan.hasNext("[ATGC]")) {
			System.out.println("Caracter no acceptado");
			scan.next();
		}
		String base = scan.nextLine(); //captura de base
	    System.out.println("Caracter acceptado: " + base);
	    return base; //se regresa valor capturado
	}
	//Funcion que agrega nodo al incicio de lista
	public void addNodeStart() {
		String base = captureChar(); //Se captura base desada
		Node newNode = new Node(base); //se genera nuevo nodo
		//Se agrega nodo al inicio de la cola en ambas condiciones
		if(size == 0) { 
			head = newNode;
			tail = newNode;
			newNode.next = head;
		} else {
			Node tmp = head;
			newNode.next = tmp;
			head = newNode;
			tail.next = head;
		}
		size++; //se incrementa tamano de nodo
	}
	//Funcion que agrega nodo al final de la lista
	public void addNodeEnd() {;
		if(size == 0) { //Si lista esta vacia se agrega al inicio de lista
			addNodeStart();
		} else { //Caso contrario  se agrega nodo al final
			String base = captureChar(); //Se captura base deseada
			Node newNode = new Node(base); //se genera nodo nuevo
			tail.next = newNode; //se agrega nodo nuevo al siguente de la cola
			tail = newNode; // cola se asigna a nodo nuevo
			tail.next = head; // se el siguente de la cola apunta al tope
			size++; //se incrementa tamano
		}
	}
	//Impresion de lista completa
	public void print() {
		Node tmp = head;
		if(size <= 0)
			System.out.println("Lista vacia");
		else {
			do {
				System.out.print(" " + tmp.data);
				tmp = tmp.next;
			} while (tmp != head);
		}
		System.out.println();
	}
	//Clase de nodo
	public class Node {
		public Node next; // Apuntador al siguente nodo
		public String data; //Dato almacenado en nodo
		// Constructor de nodo
		public Node(String data) {
			this.data = data;
		}
	}
}