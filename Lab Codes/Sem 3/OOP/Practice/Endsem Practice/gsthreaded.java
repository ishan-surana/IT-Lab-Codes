import java.util.*;

class Stack<T>
{
    T[] stack=(T[])new Object[10];
    int n=10, i=-1;
    void push(T key)
    {
        if(i==n-1) System.out.println("Full!");
        else stack[++i]=key;
    }
    void pop()
    {
        if(i<0) System.out.println("Empty!");
        else System.out.println(stack[i--]+" popped!");
    }
    void display()
    {
        if(i<0) System.out.println("Empty!");
        else for(int j=i;j>-1;j--) System.out.println(stack[j]);
    }
}

class gsthreaded
{
    public static void main(String[] args) throws InterruptedException
    {
        Scanner sc=new Scanner(System.in);
        int a=1,k;
        System.out.print("Int or String? (1/2):- ");
        int b=sc.nextInt();
        Stack<Integer> is=new Stack<>();
        Stack<String> ss=new Stack<>();
        
        while(a==1)
        {
            try{
            System.out.print("\nEnter choice:- ");
            k=sc.nextInt();
            
            switch(k)
            {
                case 1:
                Thread t1=new Thread(()->
                {
                    System.out.print("Enter element:- ");
                    sc.nextLine();
                    try{
                    if(b==1) is.push(sc.nextInt());
                    else ss.push(sc.nextLine());}
                    catch(InputMismatchException e)
                    {System.out.println("BRUH!");}
                });
                t1.start();
                t1.join();
                break;
                case 2:
                Thread t2=new Thread(()->
                {
                    if(b==1) is.pop();
                    else ss.pop();
                });
                t2.start();
                t2.join();
                break;
                case 3:
                Thread t3=new Thread(()->
                {
                    if(b==1) is.display();
                    else ss.display();
                });
                t3.start();
                t3.join();
                break;
                default:
                a=0;
                break;
            }}catch(InputMismatchException e)
                    {sc.nextLine();sc.nextLine();}
        }
    }
}