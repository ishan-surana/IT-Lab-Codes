class RunnableThread implements Runnable
{
public void run()
{
for(int i=0;i<5;i++) System.out.println("Hello World!");
}
}

class ExtendedThread extends Thread
{
public void run()
{
try
{
    for (int j=0;j<5;j++)
    {
        Thread.sleep(1000);
        System.out.println("Currently sleeping. Your queue id is "+(1+j));
    }
}
catch (Exception e)
{
    System.out.println(e);
}
for(int i=0;i<5;i++) System.out.println("World Hello!");
}
}

public class Priority
{
public static void main(String ar[])
{
RunnableThread thread1=new RunnableThread();
Thread newThread1=new Thread(thread1);
ExtendedThread thread2=new ExtendedThread();
Thread newThread2=new Thread(thread2);
newThread1.start();
newThread2.start();
for (int i=0;i<5;i++)
{
    System.out.println("Main thread running!");
}
}
}