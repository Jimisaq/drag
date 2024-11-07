class Node {
    int data;                   // Data stored in the node
    Node1 next;                  // Pointer to the next node

    Node(int data) {
        this.data = data;
        this.next = null;       // Initialize next as null
    }
}

public class LinkedList {
    Node1 head;                  // Head of the linked list

    // Method to remove duplicates of a specific key from the linked list
    public void removeDuplicates(int key) {
        boolean firstOccurrence = false;            // To track the first occurrence of the key
        Node1 current = head;                        // Start with the head of the list
        Node1 previous = null;                       // To keep track of the previous node

        while (current != null) {                    // Iterate through each node in the list
            if (current.data == key) {               // Check if the current node's data is the key
                if (!firstOccurrence) {              // If it's the first occurrence
                    firstOccurrence = true;          // Mark first occurrence
                    previous = current;              // Move previous to current
                } else {                            // If it's not the first occurrence
                    if (previous != null) {                         // Check if previous is not null
                        previous.next = current.next;               // Remove the duplicate occurrence
                    } else {
                        head = current.next;                        // Update head if the first node is a duplicate
                    }
                }
            } else {                                        // If current.data is not the key
                previous = current;                         // Move previous to current
            }   
            current = current.next;                         // Move to the next node
        }
    }

    // Method to print the linked list
    public void printList() {
        Node1 temp = head;                                   // Start with the head of the list
        while (temp != null) {                              // Iterate through each node
            System.out.print(temp.data + " -> ");           // Print the data of the current node
            temp = temp.next;                               // Move to the next node
        }
        System.out.println("null");                         // Indicate the end of the list
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();                 // Create a new linked list
        list.head = new Node1(1);                       // Add nodes to the linked list
        list.head.next = new Node1(2);
        list.head.next.next = new Node1(2);
        list.head.next.next.next = new Node1(3);
        list.head.next.next.next.next = new Node1(4);
        list.head.next.next.next.next.next = new Node1(4);
        list.head.next.next.next.next.next.next = new Node1(5);

        System.out.println("Original List:");
        list.printList();                                     

        list.removeDuplicates(2);                          // Remove duplicates of the key '2'

        System.out.println("List after removing duplicates of key 2:");
        list.printList();                                       // Print the list after removing duplicates
    }
}
