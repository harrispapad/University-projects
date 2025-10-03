import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read input file
        String filename = args[0];
        int[] inputArray = InputReader.readInput(filename);

        // Create an instance of the Tree class
        Tree tree = new Tree();

        // Create the binary tree
        Node root = null;
        int[] j = {0};
        root = tree.insert_array(root, inputArray, j);

        // Perform inorder traversal
        tree.check_lex(root);
        tree.inorderTraversal(root);
        System.out.println();
    }
}

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

class Tree {
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
            if (root.value != 0)
                System.out.print(root.value + " "); // Visit current node
            inorderTraversal(root.right); // Traverse right subtree
        }
    }

    void swap(Node node) {
        Node temp = node.left;
        node.left = node.right;
        node.right = temp;
    }

    void check_lex(Node node) {
        if (node == null) {
            return;
        }
        if (node.value == 0) {
            return;
        }

        check_lex(node.left);
        check_lex(node.right);

        if (node.left.value == 0 && node.right.value == 0) {
            return;
        } else if (node.right.value == 0) {
            if (node.min < node.left.min) {
                swap(node);
            } else {
                node.min = node.left.min;
            }
        } else if (node.left.value == 0) {
            if (node.min > node.right.min) {
                swap(node);
                node.min = node.left.min;
            } else {
            }
        } else {
            if (node.left.min > node.right.min) {
                swap(node);
                node.min = node.left.min;
            } else {
                node.min = node.left.min;
            }
        }
    }
}

class InputReader {
    public static int[] readInput(String filename) {
        File inputFile = new File(filename);
        Scanner scanner = null;
        int[] inputArray = new int[0]; // Default to an empty array
        try {
            scanner = new Scanner(inputFile);
            // Skip the first line
            if (scanner.hasNextLine()) {
                scanner.nextLine();
            }
            // Count the number of integers in the file
            int count = 0;
            while (scanner.hasNextInt()) {
                scanner.nextInt();
                count++;
            }
            scanner.close();
            // Create an array of the appropriate size
            inputArray = new int[count];
            // Read the values from the file and store them in the array
            scanner = new Scanner(inputFile); // Re-open the file
            if (scanner.hasNextLine()) {
                scanner.nextLine(); // Skip the first line again
            }
            int index = 0;
            while (scanner.hasNextInt()) {
                inputArray[index] = scanner.nextInt();
                index++;
            }
        } catch (FileNotFoundException e) {
            // Print the error message (optional)
            System.err.println("Error: File not found: " + filename);
            // You may choose to log the exception or ignore it completely
            // e.printStackTrace(); // Uncomment this line if you want to log the exception
        } finally {
            if (scanner != null) {
                scanner.close();
            }
        }
        return inputArray;
    }
}

