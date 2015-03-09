public class llist {

    Node head;

    public static void main(String [] args) {
        llist ll = new llist();
        ll.addNewNode(5);
        ll.addNewNode(15);
        ll.addNewNode(25);
        ll.addNewNode(35);
        ll.addNewNode(45);
        ll.addNewNode(55);
        
        ll.printList();
        System.out.println("Now Reversing");
        ll.reverseList();
        System.out.println("Now printing");
        ll.printList();
    }
    
    public void addNewNode(int data) {
        Node tmp = new Node(data);
        tmp.setNextNode(head);
        head = tmp;
    }
    
    public void printList() {
        Node tmp = head;
        String op = "";
        while(tmp != null) {
            op += tmp.toString();
            tmp = tmp.getNextNode();
        }
        System.out.println("Linked List is : " + op);
    }
    
    public void reverseList() {
        Node curr = head, prev = null, next = curr.getNextNode();
        while(next != null) {
            next = curr.getNextNode();
            curr.setNextNode(prev);
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    
    public class Node {
        int data;
        Node nextNode;
        
        Node(int d) {
            data = d;
        }
        
        public int getData() {
            return data;
        }
        
        public void setNextNode(Node node) {
            nextNode = node;
        }

        public Node getNextNode() {
            return nextNode;
        }

        @Override
        public String toString() {
            return data + " ";
        }
    }
}
