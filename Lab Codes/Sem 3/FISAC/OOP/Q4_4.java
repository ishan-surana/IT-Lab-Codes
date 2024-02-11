import java.util.Scanner;

class Q4_4 {
    private static String[] strings = new String[5];
    private static String searchString;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Thread s1 = new Thread(() -> {
            System.out.println("S1 thread: Enter 5 strings:");
            for (int i = 0; i < 5; i++) {
                strings[i] = scanner.nextLine();
            }
        });

        Thread s2 = new Thread(() -> {
            try {
                s1.join(); // Wait for S1 thread to finish
                System.out.println("S2 thread: Vowels and characters count in each string:");
                for (String str : strings) {
                    int vowels = 0;
                    int characters = 0;
                    for (char c : str.toCharArray()) {
                        if (isVowel(c)) {
                            vowels++;
                        }
                        characters++;
                    }
                    System.out.println("String: " + str + " - Vowels: " + vowels + " - Characters: " + characters);
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        Thread s3 = new Thread(() -> {
            try {
                s2.join(); // Wait for S2 thread to finish
                System.out.println("S3 thread: Sorting strings in ascending order:");
                for (int i = 0; i < strings.length - 1; i++) {
                    for (int j = i + 1; j < strings.length; j++) {
                        if (strings[i].compareTo(strings[j]) > 0) {
                            String temp = strings[i];
                            strings[i] = strings[j];
                            strings[j] = temp;
                        }
                    }
                }
                for (String str : strings) {
                    System.out.println(str);
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        Thread s4 = new Thread(() -> {
            try {
                s3.join(); // Wait for S3 thread to finish
                System.out.println("S4 thread: Enter a substring to search:");
                searchString = scanner.nextLine();
                boolean found = false;
                for (String str : strings) {
                    if (str.contains(searchString)) {
                        found = true;
                        System.out.println("Substring '" + searchString + "' found in: " + str);
                    }
                }
                if (!found) {
                    System.out.println("Substring '" + searchString + "' not found in any string.");
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        s1.start();
        s2.start();
        s3.start();
        s4.start();
    }

    static boolean isVowel(char c) {
        c = Character.toLowerCase(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}