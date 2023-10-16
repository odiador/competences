package ex07102023;

public class ReverseLinkedList<T> {

	public static <T> LinkedListNode<T> removeNthLastNode(LinkedListNode<T> head, int n) {

		// hallar .length()
		int length = 1;
		if (head.next != null) {
			LinkedListNode<T> nodoAux = head;
			while (nodoAux.hasNext()) {
				length++;
				nodoAux = nodoAux.next;
			}
		}
		// casos que no deben de pasar
		if (n <= 0 || n > length)
			throw new UnsupportedOperationException();
		int x = length - n;

		LinkedListNode<T> aux = head;
		LinkedListNode<T> aux2 = head;
		// condiciones para cuando n = 1 o n = length
		if (x == 0) {
			head = head.next;
			return head;
		} else if (n == 1) {
			for (int i = 0; i <= x && aux.hasNext() && aux.next.hasNext(); i++) {
				aux = aux.next;
			}
			aux.next = null;
			return head;
		}
		// qualquier otro caso
		for (int i = 0; i <= x && aux.next != null; i++) {
			aux = aux.next;
			if (i <= x - 2)
				aux2 = aux2.next;

		}
		aux2.next = aux;
		return head;
	}

	public static void main(String[] args) {
		LinkedListNode<Integer> inicio = new LinkedListNode<Integer>(5);
		inicio.next = new LinkedListNode<Integer>(7);
		inicio.next.next = new LinkedListNode<Integer>(0);
		inicio.next.next.next = new LinkedListNode<Integer>(6);
		System.out.println(inicio);
		System.out.println(removeNthLastNode(inicio, 2));
	}

	public static class LinkedList<T> {
		public LinkedListNode<T> head;

		// constructor will be used to make a LinkedList type object
		public LinkedList() {
			this.head = null;
		}

		// insertNodeAtHead method will insert a LinkedListNode at head
		// of a linked list.
		public void insertNodeAtHead(LinkedListNode<T> node) {
			if (this.head == null) {
				this.head = node;
			} else {
				node.next = this.head;
				this.head = node;
			}
		}

		public void createLinkedList(@SuppressWarnings("unchecked") T... lst) {
			for (int i = lst.length - 1; i >= 0; i--) {
				LinkedListNode<T> newNode = new LinkedListNode<T>(lst[i]);
				insertNodeAtHead(newNode);
			}
		}

	}

	public static class LinkedListNode<T> {
		public T data;
		public LinkedListNode<T> next;

		// Constructor will be used to make a LinkedListNode type object
		public LinkedListNode(T data) {
			this.data = data;
			this.next = null;
		}

		public int length() {
			if (next == null)
				return 0;
			LinkedListNode<T> nodoAux = this;
			int i = 1;
			while (nodoAux.hasNext()) {
				i++;
				nodoAux = nodoAux.next;
			}
			return i;
		}

		public boolean hasNext() {
			return next != null;
		}

		@Override
		public String toString() {
			return String.format("%s, %s", data, next == null ? "" : next);
		}

	}

}
