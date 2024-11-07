public class Node1 {
    int data;
    Node1 next;
    
    Node1(int data) {
        this.data = data;
        this.next = null;
    }
}

class SingleLinkedList {
    Node1 head;

    // Function to reverse the linked list
    public Node1 reverseSingleLinkedList(Node1 head) {
        Node1 prev = null;
        Node1 current = head;
        Node1 next = null;
        
        while (current != null) {
            next = current.next;  // Store the next Node
            current.next = prev;  // Reverse the current Node's pointer
            prev = current;       // Move prev one step forward
            current = next;       // Move current one step forward
        }
        
        return prev;  // prev is the new head of the reversed list
    }

    // Function to print the linked list
    public void printList(Node1 Node1) {
        while (Node1 != null) {
            System.out.print(Node1.data + " ");
            Node1 = Node1.next;
        }
    }

    public static void main(String[] args) {
        SingleLinkedList list = new SingleLinkedList();
        list.head = new Node1(1);
        list.head.next = new Node1(2);
        list.head.next.next = new Node1(3);
        list.head.next.next.next = new Node1(4);

        System.out.println("Original List:");
        list.printList(list.head);

        list.head = list.reverseSingleLinkedList(list.head);

        System.out.println("\nReversed List:");
        list.printList(list.head);
    }
}
