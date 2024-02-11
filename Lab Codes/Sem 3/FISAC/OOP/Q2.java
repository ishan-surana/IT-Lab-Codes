import java.util.Scanner;
class VowelWordNotFoundException extends Exception {
    public VowelWordNotFoundException(String message) {
        super(message);
    }
}

class Thread1 extends Thread {
    String sentence;

    Thread1(String sentence) {
        this.sentence = sentence;
    }

    public void run() {
        int vowelWordsCount = 0;
        String[] words = sentence.split(" ");
        String vowellist="aeiouAEIOU";
        for (String word : words) {
            String firstchar=String.valueOf(word.charAt(0));
            if (vowellist.contains(firstchar)) {
                System.out.println("Word starting with a vowel: " + word);
                vowelWordsCount++;
            }
        }

        if (vowelWordsCount==0) {
            try {
                throw new VowelWordNotFoundException("Word not found which starts with a vowel.");
            } catch (VowelWordNotFoundException e) {
                System.out.println(e);
            }
        }
    }
}

class Thread2 extends Thread {
    String sentence;

    Thread2(String sentence) {
        this.sentence = sentence;
    }

    public void run() {
        String[] words = sentence.split(" ");
        for (String word : words) {
            System.out.println("Word '" + word + "' has length = " + word.length());
        }
    }
}

class Q2 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter sentence to check:- ");
        String sentence = sc.nextLine();
        Thread1 thread1 = new Thread1(sentence);
        Thread2 thread2 = new Thread2(sentence);
        thread1.start();
        System.out.println();
        thread2.start();
        try {
        thread1.join();
        System.out.println();
        thread2.join();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
