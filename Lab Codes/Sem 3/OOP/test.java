class A extends Thread
{ public void run()
{ for(int i=1;i<=10;i++)
System.out.println("Thread A");
System.out.println("End of Thread A");
}
}
class B extends Thread
{ public void run()
{ for(int i=1;i<=10;i++)
System.out.println("Thread B");
System.out.println("End of Thread B");
}
}
class C extends Thread
{ public void run()
{ for(int i=1;i<=10;i++)
System.out.println("Thread C");
System.out.println("End of Thread C");
}
}
class test
{ public static void main(String args[]) throws InterruptedException
    /*{
        int[] a= new int[10];
        int[] b= new int[10];
        //System.out.println(a==c);
        System.out.println(a==b);
        a=b;
        System.out.println(a.equals(b));
        
    }*/
{ A a = new A();
    a.start();
    a.join();
    for(int i=0;i<10;i++) System.out.println("MAIN");
} 
}