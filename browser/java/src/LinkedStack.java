class Node {
    String data;
    Node next;

    public Node(String data) {
        this.data = data;
        this.next = null;
    }
}

public class LinkedStack {
    Node top;
    int capacity;
    int size;

    public LinkedStack(int capacity) {
        this.capacity = capacity;
        this.top = null;
        this.size = 0;
    }

    public void push(String page) {
        if (!this.isFull()) {
            Node newNode = new Node(page);
            newNode.next = top;
            top = newNode;
            size++;
        } else {
            System.out.println("Stack is full");
        }
    }

    public String pop() {
        if (!this.isEmpty()) {
            String item = top.data;
            top = top.next;
            size--;
            return item;
        }
        return "Stack is empty";
    }

    public boolean isFull() {
        return this.size == this.capacity;
    }

    public boolean isEmpty() {
        return top == null;
    }

    public void printStack() {
        Node current = top;
        while (current != null) {
            System.out.println(current.data);
            current = current.next;
        }
    }

    public void empty() {
        top = null;
        size = 0;
    }
    
}
