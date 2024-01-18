class Rectangle
{
public static void main(String args[])
{
int l=Integer.parseInt(args[0]),b=Integer.parseInt(args[1]),a=(l*b),p=2*(l+b); //Integer.parseInt takes arguments from cmd itself
System.out.println("The area of rectangle is "+a+" and the perimeter is "+p+".");
}
}