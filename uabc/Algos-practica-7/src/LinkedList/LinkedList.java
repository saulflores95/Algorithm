package LinkedList;

public class LinkedList {
	Node head; // Tope de la lista
	class Node { //Se genera clase tipo nodos
		String data; //El dato que se contiene el nodo 
		Node next; // El siguiente nodo que apunta el nodo actual
		// Constructor de nodo
		Node(String d) {
			data = d;
		}
	}
	// funcion que itera lista e imprime su contenido
	public void printList() {
		Node node = head; //igualamos el valor a head para no perder el valor original
		while(node != null ) { // si nodo is igual a nulo salimos del siclo
			System.out.print(node.data + " "); //impresion de los datos en una sola lina
			node = node.next; //avansamos al siguente nodo de la lista
		}
	}
	//Funcion que agrega una palabra al final de la lista
	public void addToEnd(String data) {
		Node newNode = new Node(data); // Reservamos espacio para nodo
		if(head == null ) { // Si el tope se encuentra vacio generamos una lista nueva
			head = new Node(data); // Generamos nodo y lo asignamos a la variable head
			return; // salimos de la funcion
		}
		newNode.next = null; // el nodo nuevo como es el ultimo el nodo siguiente apunta a nulo
		Node last = head; // el ultimo nodo es el tope
		while(last.next != null) // iteramos hasta el fin del nodo
			last = last.next;
		last.next = newNode; // ultimo nodo se iguala al nuevo nodo
		System.out.println("Valor " + data + " agregado al final");
		return; // Salimos de la funcion
	}
	//	funcion que agrega valor despues de una palabra indicada con la variable afterOf
	public void insertAfter(String data, String afterOf) {
		if(head == null) {	// Si el tope esta vacio salimos de la funcion
			System.out.println("Lista vacia, saliendo..."); // indicamos que la lista esta vacia
			return; //	salimos
		}
		Node tmpNode = head; // en caso que si tenga contenido la lista igualamos a tmpNode
		while(tmpNode.data.equals(afterOf) != true) { //	verificamos que el dato no sea igual al indicado para seguir iterando
			tmpNode = tmpNode.next; //	Igualamos el valor del siguiente nodo al nodo actual
			if(tmpNode == null) { //	ESTO NO ME GUSTA PERO ECLIPSE ESTA ACTUANDO REVELDE y no me deja poner esto en el while 
				System.out.println("Valor no se presento en la lista, dato " + data + " no sera agregado"); //si tmpNode es nulo el valor no se encuentra y salimos de esta funcion
				return;//	salida
			}
		}
		Node newNode = new Node(data); //generamos nodo con dato nuevo
		newNode.next = tmpNode.next; //apuntamos el nodo nuevo lo que resta de la lista
		tmpNode.next = newNode; // nuevo nodo al contenido previo de la lista
	}
    //	funcion push que agrega valores al inicio de la lista solo la programe para efectos de testing
	public void push(String data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }
    //	funcion que elimina nodo seleccionado
	public void remove(String data) {
		//si lista se encuentra vacia
		if(head == null) {
			System.out.println("Lista vacia, saliendo...");  // indicamos al usuario
			return; // salimos
		}
    	Node tmpNode = head;//	igualmos tope a tmpNode
    	//	Salimos un nodo antes al deseado a eliminar para poder ignorarlo
		while(tmpNode.next.data.equals(data) != true) { //verificamos que el dato no sea igual al indicado para seguir iterando
			tmpNode = tmpNode.next; //Igualamos el valor del siguiente nodo al nodo actual
			if(tmpNode == null) {
				System.out.println("Valor no se presento en la lista, dato " + data + " no sera removido");
				return;
			}
		}
		System.out.println("Valor " + tmpNode.next.data + " removido"); // indicamos el valor removido
		tmpNode.next = tmpNode.next.next; //apuntamos el valor next que es el nodo que queremos elimnar y lo remplazamos por el nodo siguiente al deseado a eliminar
    }
}
