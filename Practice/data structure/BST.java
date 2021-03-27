import java.util.*;
class BST{
    static class Node{
        int data;
        Node left; 
        Node right; 
        Node(int data){
            this.data = data;
        }
    }
    static Node insert(Node root, int data){
        if(root == null){
            root = new Node(data);
        }
        if(data <= root.data){
            root.left = insert(root.left, data);
        }
        else{
            root.right = insert(root.right, data); 
        }
        return root; 

    }
    static void inOrder(Node root){
        if(root == null) return; 
        inOrder(root.left);
        System.out.printf(" %d", root.data);
        inOrder(root.right); 
    }

    public static void main(String[] args){
        
        Node root = null;

        root = insert(root, 3);
        root = insert(root, 2);
        root = insert(root, 1); 

        inOrder(root);System.out.println(); 
    }
}