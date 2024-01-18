import java.util.Scanner;
class Time{
    int h;
    int m;
    int s;

    Time(){
        h=m=s=0;
    }

    Time(int hr, int min, int sec){
        h=hr;
        m=min;
        s=sec;
    }

    void display()
    {
	    if(h<10)
        {
            if(m<10)
            {
                if(s<10)
                System.out.println("\nTime in hh:mm:ss format:- 0"+h+":0"+m+":0"+s);
                else System.out.println("\nTime in hh:mm:ss format:- 0"+h+":0"+m+":"+s);
            }
            else if(s<10)
            {
                System.out.println("\nTime in hh:mm:ss format:- 0"+h+":"+m+":0"+s);
            }
            else System.out.println("\nTime in hh:mm:ss format:- 0"+h+":"+m+":"+s);
        }
        else
        {
            if(m<10)
            {
                if(s<10)
                System.out.println("\nTime in hh:mm:ss format:- "+h+":0"+m+":0"+s);
                else System.out.println("\nTime in hh:mm:ss format:- "+h+":0"+m+":"+s);
            }
            else if(s<10)
            {
                System.out.println("\nTime in hh:mm:ss format:- "+h+":"+m+":0"+s);
            }
            else System.out.println("\nTime in hh:mm:ss format:- "+h+":"+m+":"+s);
        }
    }

    void add(Time a, Time b)
    {
        h=(a.h+b.h);
        if((a.m+b.m)<60) m=(a.m+b.m);
        else
        {
            m=((a.m+b.m)%60);
            ++h;
        }
        if((a.s+b.s)<60) s=(a.s+b.s);
        else
        {
            s=((a.s+b.s)%60);
            ++m;
        }
    }
}

class TimeAdd{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        char c;
        int hr,min,sec;
        Time t1=new Time();
        Time t2=new Time();
        System.out.print("Do you want to input time 1? (y/n)");
        c = sc.next().charAt(0);
        if(c=='y') {
            System.out.print("\nEnter hours:- ");
            hr = sc.nextInt();
            System.out.print("Enter minutes:- ");
            min = sc.nextInt();
            System.out.print("Enter seconds:- ");
            sec = sc.nextInt();
            t1=new Time(hr, min, sec);
        }
        System.out.print("Do you want to input time 2? (y/n)");
        c = sc.next().charAt(0);
        if(c=='y') {
            System.out.print("Enter hours:- ");
            hr = sc.nextInt();
            System.out.print("Enter minutes:- ");
            min = sc.nextInt();
            System.out.print("Enter seconds:- ");
            sec = sc.nextInt();
            t2=new Time(hr, min, sec);
        }
	System.out.print("\nFor Time 1");
        t1.display();
	System.out.print("\nFor Time 2");
        t2.display();
        Time t3=new Time();
        t3.add(t1, t2);
        t3.display();
    }
}