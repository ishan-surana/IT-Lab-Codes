import java.util.Scanner;

class Stack<T> {
    T[] stack = (T[]) new Object[10];
    int n = 10, i = -1;

    synchronized void push(T key) {
        if (i == n - 1) System.out.println("Full!");
        else stack[++i] = key;
    }

    synchronized void pop() {
        if (i < 0) System.out.println("Empty!");
        else System.out.println(stack[i--] + " popped!");
    }

    synchronized void display() {
        for (int j = i; j > -1; j--) System.out.println(stack[j]);
    }
}

class PushOperation<T> implements Runnable {
    private Stack<T> stack;
    private Scanner scanner;

    public PushOperation(Stack<T> stack, Scanner scanner) {
        this.stack = stack;
        this.scanner = scanner;
    }

    @Override
    public void run() {
        while (true) {
            System.out.print("\nEnter choice for push operation (1 for Integer, 2 for String, 0 to exit):- ");
            int k = scanner.nextInt();
            if (k == 0) break;

            System.out.print("Enter element for push operation:- ");
            if (k == 1) {
                stack.push((T) Integer.valueOf(scanner.nextInt()));
            } else if (k == 2) {
                stack.push((T) scanner.next());
            }
        }
    }
}

class PopOperation<T> implements Runnable {
    private Stack<T> stack;
    private Scanner scanner;

    public PopOperation(Stack<T> stack, Scanner scanner) {
        this.stack = stack;
        this.scanner = scanner;
    }

    @Override
    public void run() {
        while (true) {
            System.out.print("\nEnter choice for pop operation (1 for Integer, 2 for String, 0 to exit):- ");
            int k = scanner.nextInt();
            if (k == 0) break;

            if (k == 1) {
                stack.pop();
            } else if (k == 2) {
                stack.pop();
            }
        }
    }
}

class DisplayOperation<T> implements Runnable {
    private Stack<T> stack;
    private Scanner scanner;

    public DisplayOperation(Stack<T> stack, Scanner scanner) {
        this.stack = stack;
        this.scanner = scanner;
    }

    @Override
    public void run() {
        while (true) {
            System.out.print("\nEnter choice for display operation (1 for Integer, 2 for String, 0 to exit):- ");
            int k = scanner.nextInt();
            if (k == 0) break;

            if (k == 1) {
                stack.display();
            } else if (k == 2) {
                stack.display();
            }
        }
    }
}

class threadgenstack {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int b = sc.nextInt();
        Stack<Integer> is = new Stack<>();
        Stack<String> ss = new Stack<>();
        if(b==1){
        Thread pushThread = new Thread(new PushOperation<>(is, sc));
        Thread popThread = new Thread(new PopOperation<>(is, sc));
        Thread displayThread = new Thread(new DisplayOperation<>(is, sc));}
        else{
        Thread pushThread = new Thread(new PushOperation<>(ss, sc));
        Thread popThread = new Thread(new PopOperation<>(ss, sc));
        Thread displayThread = new Thread(new DisplayOperation<>(ss, sc));}

        // Start the threads
        pushThread.start();
        popThread.start();
        displayThread.start();
    }
}
