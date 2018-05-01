package doublelinkedlists;

import java.util.Scanner;

public class DoubleLinkedList {
	public Node head;
    static final Scanner scan = new Scanner(System.in);
	public class Node {
		int price;
		int expYear;
		String expMonth;
		String description;
		String productName;
		Node prev; // no se asigna
		Node next;// no se asigna
		// Constructor de nodo
		public Node(int price2, int expYear2, String expMonth2, String description2, String productName2) {
			price = price2;
			expYear = expYear2;
			expMonth = expMonth2;
			description = description2;
			productName = productName2;
		}
	}
	//	Funcion que retorna un nodo sin tener prev o next asignando
	public Node createNode() {
		System.out.println("Agregar medicamento nuevo.");
		System.out.println("Cual es el precio?");
		String price = scan.nextLine();
		System.out.println("Cual es el mes de vencimiento. Ejemplo 'Mayo'?");
		String expMonth = scan.nextLine();
		System.out.println("Cual es el la anio de vencimiento. Ejemplo '2018'?");
		String expYear = scan.nextLine();
		System.out.println("Ingrese la descripcion del medicamento");
		String description = scan.nextLine();
		System.out.println();
		System.out.println("Ingrese el nombre del medicamento");
		String productName = scan.nextLine();
		Node newNode = new Node(Integer.parseInt(price), Integer.parseInt(expYear), expMonth, description, productName);
		return newNode; //regresa el nodo creado
	}
	//	funcion que imprime contenido de nodo
	public void printNode(Node node) {
		System.out.println();
		System.out.println("Nombre de medicamento: " + node.productName);
		System.out.println("Descripcion: " + node.description);
		System.out.println("Fecha de maxima de consumo: " + node.expMonth + ", " + node.expYear);
		System.out.println("Precio: " + node.price);
		System.out.println();

	}
	// funcion que compara si el string a es mas grande que string b
	public Boolean isBigger(Node a, Node b) {
		int compare = a.productName.compareTo(b.productName); // compare nos indica el estado de la comparacion
		Boolean ans;
		if (compare < 0) {  //si compare es menor a en emenor a b
			ans = false;
		}
		else if (compare > 0) { // si comapre es mayor a cero significa que el a es mayor o igual a b
			ans = true;
		}
		else {  
			ans = true;
		} 
		return ans;	 //se regresa la respuesta
	}
	// funcion que inserta en lista alfabeticamente
	public void sortedInsert(Node newNode) {
		Node curr;
		if(head == null) {
			head = newNode;
			return;
		} else if (isBigger(head, newNode)) {
			newNode.next = head;
			newNode.next.prev = newNode;
			head = newNode;
		} else {
			curr = head;
			while(curr.next != null && isBigger(newNode, curr.next))
				curr = curr.next;
			newNode.next = curr.next;
			if(curr.next != null)
				newNode.next.prev = newNode;
			curr.next = newNode;
			newNode.prev = curr;
		}
	}
	// funcion que imprime toda una lista en orden alfabetico
	public void printList(Node node) {
		Node last = null;
		System.out.println("Impresion para enfrente");
		while(node != null) {
			printNode(node);
			last = node;
			node = node.next;
		}
		//System.out.println("Impresion para atras");
	    while (last != null) {
			//printNode(last);
	        last = last.prev;
	    }
	}
	// funcion que remueve un nodo usando el nombre coo referencia
	public void removeNode(Node node, String nameToRemove) {
		Boolean bool = false;
		if(node == null) {
			System.out.println("Lista vacia");
			return;
		}
		while(bool != true && node != null) {
			if(node.productName.toLowerCase().equals(nameToRemove.toLowerCase())) {
				System.out.println("Producto localizado...");
				bool = true;
			}
			if(bool != true)
				node = node.next;
		}
		if(node == null) {
			System.out.println("No se encontro elemento");
			return;
		} else {
			if(node.prev != null && node.next != null) {// Si el nodo esta en medio de la lista
				Node prev = node.prev;
				Node next = node.next;
				node = next;
				node.prev = prev;
				prev.next = node;
				System.out.println("Producto eliminado...");				
			} else if(node.next == null) { //Si el nodo es el ultimo en la lista
				node.prev.next = null;
				System.out.println("Producto eliminado...");				
			} else if(node.prev == null) { //Si el nodo esta al inicio de la lista
				System.out.println("Heeey");
				node = node.next;
				node.prev = null;
				head = node;
			} else {
				node = null;
			}
		}
	}
}
