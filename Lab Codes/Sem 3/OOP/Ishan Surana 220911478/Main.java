class Node<T> {
    T data;
    Node<T> next;
    public Node(T data) {
        this.data = data;
        this.next = null;}}

class LinkedList<T> {
    Node<T> head;
    public LinkedList() {
        this.head = null;}

    public void add(T data) {
        Node<T> newNode = new Node<>(data);
        if (head == null) {
            head = newNode;} 
	else {
            Node<T> current = head;
            while (current.next != null) {
                current = current.next;}
            current.next = newNode;
        }
    }

    public void remove(T data) {
        if (head == null) {
            return;}
        if (head.data.equals(data)) {
            head = head.next;
            return;}
        Node<T> current = head;
        while (current.next != null) {
            if (current.next.data.equals(data)) {
                current.next = current.next.next;
                return;}
            current = current.next;
        }
    }

    public void traverse() {
        Node<T> current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }
}


public class Main{
    public static void main(String[] args) {

        LinkedList<Number> list = new LinkedList<>();

        list.add(1);
        list.add(2.5);
        list.add(3);
        list.add(4.2);

        list.traverse();
        list.remove(3);
        list.traverse();
    }
}