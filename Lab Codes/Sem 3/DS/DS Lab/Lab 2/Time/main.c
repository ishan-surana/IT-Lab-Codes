#include <stdio.h>
#include <stdlib.h>

struct time
{
    int hr;
    int min;
    int sec;
}s[4];

int i;

void scan(struct time s[])
{
    for(i=0;i<2;i++)
    {
        printf("Enter Time %d:-\n\n",1+i);
        printf("Enter hours:- ");
        scanf("%d",&s[i].hr);
        printf("Enter minutes:- ");
        scanf("%d",&s[i].min);
        printf("Enter seconds:- ");
        scanf("%d",&s[i].sec);
        printf("\n\n");
    }
}

void print(struct time s[])
{
    for(i=0;i<2;i++)
        printf("Time %d = %d:%d:%d\n",1+i,s[i].hr,s[i].min,s[i].sec);
}

void add(struct time s[])
{
    if((s[0].sec+s[1].sec) < 60) s[2].sec=s[0].sec+s[1].sec;
    else
    {
        s[2].sec=((s[0].sec+s[1].sec)%60);
        ++s[2].min;
    }

    if(s[0].min+s[1].min < 60) s[2].min=(s[0].min+s[1].min);
    else
    {
        s[2].min+=((s[0].min+s[1].min)%60);
        ++s[2].hr;
    }

    s[2].hr+=(s[0].hr+s[1].hr);
    printf("Sum of times = %d:%d:%d\n",s[2].hr,s[2].min,s[2].sec);
}

/*
void diff(struct time s[])
{
    if(s[1].hr >= s[0].hr)
    {
        if(s[1].min >= s[0].min)
        {
            s[3].min=(s[1].min - s[0].min);
            if(s[1].sec >= s[0].sec)
            s[3].sec=(s[1].sec - s[0].sec);
            else s[3].sec=(s[0].sec - s[1].sec);
        }
        else
    }
}
*/

void diff(struct time s[])
{
    int s1=(3600*s[0].hr+60*s[0].min+s[0].sec), s2=(3600*s[1].hr+60*s[1].min+s[1].sec), secdiff;
    if(s1>s2)
        secdiff=(s1-s2);
    else
        secdiff=(s2-s1);
    s[3].hr=secdiff/3600;
    s[3].min=(secdiff%3600)/60;
    s[3].sec=secdiff%60;
    printf("Difference of times = %d:%d:%d\n",s[3].hr,s[3].min,s[3].sec);
}

int main()
{
    s[2].hr=0;s[2].min=0;s[2].sec=0;
    s[3].hr=0;s[3].min=0;s[3].sec=0;
    scan(s);
    print(s);
    add(s);
    diff(s);
    return 0;
}
