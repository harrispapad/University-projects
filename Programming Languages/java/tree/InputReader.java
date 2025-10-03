import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class InputReader {
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
