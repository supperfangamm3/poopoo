import java.util.Scanner;
import java.io.*;
import java.util.concurrent.atomic.AtomicInteger;

class Script {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the file name: ");
        String fileName = scanner.nextLine();
        File file = new File(fileName);
        Scanner fileScanner = null;
        try {
            fileScanner = new Scanner(file);
        } catch (FileNotFoundException e) {
            System.out.println("Error: File not found.");
            System.exit(1);
        }
        while (fileScanner.hasNextLine()) {
            String line = fileScanner.nextLine();
            System.out.println(line);
        }
        fileScanner.close();
        int[] numbers = {1, 2, 3, 4, 5};
        for (int number : numbers) {
            System.out.print(number + " ");
        }
        System.out.println();
        AtomicInteger sum = new AtomicInteger();
        forEach(numbers, (int n) -> sum.addAndGet(n));
        System.out.println("Sum: " + sum);
    }
    interface IntConsumer {
        void accept(int value);
    }
    public static void forEach(int[] array, IntConsumer function) {
        for (int value : array) {
            function.accept(value);
        }
    }
}
