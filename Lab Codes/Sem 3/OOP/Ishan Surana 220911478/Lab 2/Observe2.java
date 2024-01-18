class Observe2
{
public static void main(String args[])
{
boolean x =true;
int y = x;
System.out.println(x+" "+y);  //Error:- boolean cannot be converted to int
boolean a =true;
int b =(int)a;
System.out.println(a+" "+b);  //Error:- boolean cannot be converted to int
}
}