import java.util.Scanner;
class Complex{
    int real;
    int im;
    Complex()
    {
        real=0;
        im=0;
    }
    Complex(int a, int b)
    {
        real=a;
        im=b;
    }
    void display(){
        System.out.print(real+" + "+im+"i");
    }

    void add(int a, Complex b){
        real=(a+b.real);
        im=b.im;
    }

    void add(Complex a, Complex b){
        real=(a.real+b.real);
        im=(a.im+b.im);
    }
}

class ComplexSum{
    public static void main(String[] args) {
        int x;
        char ch;
        Scanner sc=new Scanner(System.in);
        Complex a=new Complex();
        Complex b=new Complex();
        Complex c=new Complex();
        System.out.println("Do you want to add an integer and a complex number? (y/n)");
        ch=sc.next().charAt(0);
        if(ch=='y'){
            System.out.print("\nEnter integer:- ");
            x=sc.nextInt();
            System.out.print("\nEnter real and imaginary parts of complex number a+ib separately, ie as 'a b':- ");
            a.real=sc.nextInt();
            a.im=sc.nextInt();
            c.add(x, a);
        }
        else if(ch=='n'){
            System.out.println("Do you want to add 2 complex numbers? (y/n)");
            ch=sc.next().charAt(0);
            if(ch=='y'){
            System.out.print("\nEnter real and imaginary parts of complex number 1 [a+ib] separately, ie as 'a b':- ");
            a.real=sc.nextInt();
            a.im=sc.nextInt();
            System.out.print("\nEnter real and imaginary parts of complex number 2 [a+ib] separately, ie as 'a b':- ");
            b.real=sc.nextInt();
            b.im=sc.nextInt();
            c.add(a, b);
            System.out.println("Result after addition is = ");
            c.display();
        }
    }
    else;
}
}