
import java.util.*;
class LinkedList{
    static class Node{
        int data;
        Node next;
        Node(int data){
            this.data = data;
            this.next = null;
        }
    }
    static Node insert(Node node, int data){
        Node newNode = new Node(data);
        newNode.next = node;
        return newNode;
    }
    static void print(Node node){
        while(node!=null){
            System.out.printf("%d ", node.data);
            node = node.next;
        }
        System.out.println();
    }
    static Node reverse(Node node){
        Stack<Node> stack = new Stack<>(); 
        while(node!=null){
            stack.push(node); 
            node = node.next;
        }
        Node head = stack.peek(); 
        Node temp = head;
        while(!stack.isEmpty()){
            temp.next = stack.pop();
            temp = temp.next;
        }
        temp.next = null;
        return head; 
    }
    public static void main(String[] args) {
        Node head = null; 
        head = insert(head, 8);
        head = insert(head, 3);
        head = insert(head, 5); 
        head = insert(head, 2); 
        print(head);
        head = reverse(head); 
        print(head);
    }
}