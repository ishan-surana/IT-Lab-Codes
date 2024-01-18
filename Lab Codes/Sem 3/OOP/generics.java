import java.util.*;
class Gen<T>
{
    T name;
    public void setName(T name)
    {
        this.name = name;
    }
    public T getName()
    {
        return name;
    }
}

class generics
{
    public static void main(String[] args)
    {
        int choice;
        String NameS;
        Integer NameI;

        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("1.Integer");
            System.out.println("2.String");
            System.out.println("3.Exit");
            System.out.println("Enter Choice");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    Gen<Integer> Obji = new Gen<Integer>();
                    System.out.println("Enter Integer");
                    NameI = sc.nextInt();
                    Obji.setName(NameI);
                    System.out.println("You entered "+Obji.getName());
                    break;
                case 2:
                    Gen<String> Objs = new Gen<String>();
                    System.out.println("Enter String");
                    sc.nextLine();
                    NameS = sc.nextLine();
                    Objs.setName(NameS);
                    System.out.println("You entered "+Objs.getName());
                    break;
            }

        } while (choice != 3);
    }
}