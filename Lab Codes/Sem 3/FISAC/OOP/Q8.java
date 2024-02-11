import java.util.ArrayList;
import java.util.Collection;
import java.util.Scanner;

class PrimeCounter {
    static <T extends Number> int countPrimes(Collection<T> c) {
        int count = 0;
        for (T number : c) {
            if (isPrime(number.intValue())) {
                count++;
            }
        }
        return count;
    }

    static boolean isPrime(int n) {
        if(n<=1) return false; 
        for(int i=2;i<n;i++)
        if(n%i==0) return false;
        return true;
    }
}

class Q8 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Integer> integerList = new ArrayList<>();

        System.out.print("Enter the number of elements in the collection: ");
        int n = scanner.nextInt();

        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            int number = scanner.nextInt();
            integerList.add(number);
        }

        int primeCount = PrimeCounter.countPrimes(integerList);
        System.out.println("Number of prime numbers in the collection: " + primeCount);

        scanner.close();
    }
}