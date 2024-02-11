import java.util.Scanner;

class StringCheck {
    static String[] strings = new String[5];
    static String searchString, commonVowels;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 5; i++) {
            System.out.print("Enter string " + (i + 1) + ": ");
            strings[i] = sc.nextLine();
        }

        Thread s1 = new S1Thread(strings);
        Thread s2 = new S2Thread(strings);
        Thread s3 = new S3Thread(strings);
        Thread s4 = new S4Thread(strings);

        s1.start();

        try {
        s2.start();
            s2.join();
        } catch (InterruptedException e) {
            System.out.println(e);
        }
        try {
        s4.start();
            s4.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        try {
        s3.start();
            s3.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Sorted Strings:");
        for (String str : strings) {
            System.out.println(str);
        }

        commonVowels = findCommonVowels(strings[0], strings[1]);
        System.out.println("Common vowels in the first two strings: " + commonVowels);
    }

    static void sortStrings(String[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i].compareTo(arr[j]) > 0) {
                    String temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    static void searchSubstring(String[] arr, String target) {
        for (String str : arr) {
            if (str.contains(target)) {
                System.out.println("Substring found in string: " + str);
            }
        }
    }

    static String findCommonVowels(String str1, String str2) {
        StringBuilder common = new StringBuilder();
        for (char c : str1.toCharArray()) {
            if ("AEIOUaeiou".contains(String.valueOf(c))) {
                if (str2.contains(String.valueOf(c))) {
                    if (common.length() > 0) common.append(", ");
                    common.append(c);
                }
            }
        }
        return common.toString();
    }
}

class S1Thread extends Thread {
    String[] strings;
    public S1Thread(String[] strings) {
        this.strings = strings;
    }

    
    public void run() {
        System.out.println("S1: Storing strings in an array");
    }
}

class S2Thread extends Thread {
    private String[] strings;

    public S2Thread(String[] strings) {
        this.strings = strings;
    }

    
    public void run() {
        System.out.println("S2: Displaying the number of vowels and characters in each string");
        for (String str : strings) {
            int vowels = 0;
            int characters = 0;
            for (char c : str.toCharArray()) {
                characters++;
                if ("AEIOUaeiou".contains(String.valueOf(c))) {
                    vowels++;
                }
            }
            System.out.println("String: " + str);
            System.out.println("Number of characters: " + characters);
            System.out.println("Number of vowels: " + vowels);
        }
    }
}

class S3Thread extends Thread {
    private String[] strings;

    public S3Thread(String[] strings) {
        this.strings = strings;
    }

    
    public void run() {
        System.out.println("S3: Sorting strings in ascending order");
        StringCheck.sortStrings(strings);
    }
}

class S4Thread extends Thread {
    private String[] strings;

    public S4Thread(String[] strings) {
        this.strings = strings;
    }

    
    public void run() {
        System.out.println("S4: Searching a substring");
        System.out.print("Enter a substring to search: ");
        Scanner sc=new Scanner(System.in);
        String target = sc.nextLine();
        StringCheck.searchSubstring(strings, target);
    }
}
