class Observe
{
public static void main(String args[])
{
int x =10;
double y = x; 
System.out.println(y);  //Output = 10.0

/*double a = 10.5;
int b = a; 
System.out.println(b);*/   //Commented bcoz no o/p; instead Error (lossy coversion)

double p = 10.5;
int q = (int) p;
System.out.println(q); //Output = 10;
}
}