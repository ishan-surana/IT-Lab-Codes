import java.util.Scanner;

class F1 extends Thread {
    int[] array;

    F1(int[] array) {
        this.array = array;
    }

    public void run() {
        System.out.println("F1 Thread: Printing array elements in order");
        for (int num : array) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}

class F2 implements Runnable {
    int[] array;

    F2(int[] array) {
        this.array = array;
    }

    public void run() {
        System.out.println("F2 Thread: Printing array elements in reverse order");
        for (int i = array.length - 1; i >= 0; i--) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }
}

class datathread {
    public static void main(String[] args) throws InterruptedException
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int size = scanner.nextInt();

        int[] array = new int[size];

        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }

        // Creating objects for F1 and F2
        F1 f1Thread = new F1(array);
        F2 f2Runnable = new F2(array);
        Thread f2Thread = new Thread(f2Runnable);

        // Starting the threads
        f1Thread.start();
        f1Thread.join();
        f2Thread.start();
    }
}
