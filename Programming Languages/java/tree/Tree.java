class Node {
    int value;
    int min;
    Node left;
    Node right;

    Node(int value) {
        this.value = value;
        this.min = value;
        this.right = null;
        this.left = null;
    }
}

public class Tree {
    Node insert_array(Node root, int[] a, int[] j) {
        if (j[0] >= a.length) {
            return null;
        }

        if (a[j[0]] == 0) {
            root = new Node(a[j[0]]);
            return root;
        }

        root = new Node(a[j[0]]);

        if (a[j[0]] != 0) {
            j[0]++;
            root.left = insert_array(root.left, a, j);
        }

        j[0]++;
        root.right = insert_array(root.right, a, j);

        return root;
    }    

    public void inorderTraversal(Node root) {
        if (root != null) {
            inorderTraversal(root.left); // Traverse left subtree
            if(root.value != 0)
                System.out.print(root.value + " "); // Visit current node
            inorderTraversal(root.right); // Traverse right subtree
        }
    }

    void swap(Node node) {
        Node temp = node.left;
        node.left = node.right;
        node.right = temp;
    }

    void check_lex(Node node){
        if (node == null){
            return;
        }
        if (node.value == 0){
            return;
        }

        check_lex(node.left);
        check_lex(node.right);

        if(node.left.value == 0 && node.right.value == 0){
            return;
        }
        else if (node.right.value == 0) {
            if (node.min < node.left.min) {
                swap(node);
            } else {
                node.min = node.left.min;
            }
        }
        else if (node.left.value == 0) {
            if (node.min > node.right.min) {
                swap(node);
                node.min = node.left.min;
            } else {
            }
        }
        else { 
            if (node.left.min > node.right.min) {
                swap(node);
                node.min = node.left.min;
            } else {
                node.min = node.left.min;
            }
        }
    }


}