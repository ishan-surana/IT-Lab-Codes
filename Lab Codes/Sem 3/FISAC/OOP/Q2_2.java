import java.util.Scanner;

class VowelThread extends Thread {
    private String sentence;
    private int vowelWordCount;

    public VowelThread(String sentence) {
        this.sentence = sentence;
        vowelWordCount = 0;
    }

    @Override
    public void run() {
        String[] words = sentence.split(" ");
        for (String word : words) {
            String cleanWord = word.trim().toLowerCase();
            if (!cleanWord.isEmpty()) {
                char firstChar = cleanWord.charAt(0);
                if (isVowel(firstChar)) {
                    vowelWordCount++;
                }
            }
        }
    }

    public int getVowelWordCount() {
        return vowelWordCount;
    }

    private boolean isVowel(char c) {
        return "aeiou".contains(String.valueOf(c));
    }
}

class WordLengthThread extends Thread {
    private String sentence;

    public WordLengthThread(String sentence) {
        this.sentence = sentence;
    }

    @Override
    public void run() {
        String[] words = sentence.split(" ");
        for (String word : words) {
            String cleanWord = word.trim();
            if (!cleanWord.isEmpty()) {
                System.out.println("Word: " + cleanWord + ", Length: " + cleanWord.length());
            }
        }
    }
}

class Q2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a sentence: ");
        String inputSentence = scanner.nextLine();
        
        VowelThread vowelThread = new VowelThread(inputSentence);
        WordLengthThread wordLengthThread = new WordLengthThread(inputSentence);

        vowelThread.start();
        wordLengthThread.start();

        try {
            vowelThread.join();
            wordLengthThread.join();
            int vowelWordCount = vowelThread.getVowelWordCount();
            if (vowelWordCount == 0) {
                throw new NoVowelWordFoundException("Word not found which starts with a vowel.");
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        } catch (NoVowelWordFoundException e) {
            System.out.println(e.getMessage());
        }
        
        scanner.close();
    }
}

class NoVowelWordFoundException extends Exception {
    public NoVowelWordFoundException(String message) {
        super(message);
    }
}