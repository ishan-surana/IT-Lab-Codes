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
        for(int j=i;j>-1;j--) System.out.println(stack[j]);
    }
}

class genstack
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int a=1,k,b=sc.nextInt();
        Stack<Integer> is=new Stack<>();
        Stack<String> ss=new Stack<>();
        while(a==1)
        {
            System.out.print("\nEnter choice:- ");
            k=sc.nextInt();
            switch(k)
            {
                case 1:
                System.out.print("Enter element:- ");
                sc.nextLine();
                if(b==1) is.push(sc.nextInt());
                else ss.push(sc.nextLine());
                break;
                case 2:
                if(b==1) is.pop();
                else ss.pop();
                break;
                case 3:
                if(b==1) is.display();
                else ss.display();
                break;
                default:
                a=0;
                break;
            }
        }
    }
}