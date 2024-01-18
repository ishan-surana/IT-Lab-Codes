#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[100];
    long roll;
    char grade;
}s[100];

int n,i;

void scan(struct student s[])
{
    for(i=0;i<n;i++)
    {
        printf("Enter name:- ");
        scanf("%s",s[i].name);
        printf("Enter roll number:- ");
        scanf("%ld",&s[i].roll);
        printf("Enter grade:- ");
        getchar(); //scanf("%c") directly takes in \n as the char automatically so we consume it so that we scan char that user inputs
        scanf("%c",&s[i].grade);
        printf("\n\n");
    }

}

void print(struct student s[])
{
    for(i=0;i<n;i++)
    {
        printf("STUDENT %d:-\n",i+1);
        printf("\tName:- %s\n",s[i].name);
        printf("\tRoll Number:- %ld\n",s[i].roll);
        printf("\tGrade:- %c\n",s[i].grade);
        printf("\n\n");
    }
}

void print_after_sort(struct student s[])
{
    for(i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(s[j].roll>s[j+1].roll)
            {
                struct student temp = s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
    print(s);
}

int main()
{
    printf("Enter number of students:- ");
    scanf("%d",&n);
    printf("Enter student details.\n\n");
    scan(s);
    printf("Structure BEFORE sorting:-\n\n");
    print(s);
    printf("Structure AFTER sorting:-\n\n");
    print_after_sort(s);
    return 0;
}



/*
int main() {
   struct student s1[2];

   for(int i=0; i<2; i++)
   {
        printf("Enter name: ");

        scanf("%[^\n]%*c", s1[i].name);
        fflush(stdin);
        printf("Enter age: ");
        scanf("%d", &s1[i].age);
        fflush(stdin);
*/
