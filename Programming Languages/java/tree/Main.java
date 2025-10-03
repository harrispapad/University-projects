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
