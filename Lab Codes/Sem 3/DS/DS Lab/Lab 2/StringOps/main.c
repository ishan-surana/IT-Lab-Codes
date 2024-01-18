#include <stdio.h>
#include <string.h>

int main()
{
    char a[100],b[100],c[100],key;
    int n;
    printf("Enter option number of the operation you want to perform:-\n\n1) String Length\n2) String Concatenation\n3) String Comparison\n4) Substring Insertion\n5) Substring Deletion\n\n");
    scanf("%d",&n);
    printf("\n");
	do{
    switch(n)
    {
        case 1: {
        printf("Enter string:- ");
        scanf("%s", a);
        printf("\nLength of the string is %d.",strlen(a));
        break;
        }

        case 2: {
        printf("Enter string 1:- ");
        scanf("%s", a);
        printf("Enter string 2:- ");
        scanf("%s", b);
        printf("Concatenated string is:- %s",strcat(a,b));
        break;
        }

        case 3: {
        printf("Enter string 1:- ");
        scanf("%s", a);
        printf("Enter string 2:- ");
        scanf("%s", b);
        printf("\n");
        if(strcmp(a,b)>0) printf("String 1 is greater in value than String 2.");
        else if(strcmp(a,b)<0) printf("String 2 is greater in value than String 1.");
        else printf("Both strings are equal.");
        printf("\n");
        break;
        }

        case 4: {
        int i,j,k,l,p;
        printf("Enter string:- ");
        scanf("%s", a);
        printf("Enter substring to be inserted:- ");
        scanf("%s", b);
        int ila=strlen(a), ilb=strlen(b);
        printf("Enter position of insertion:- ");
        scanf("%d",&p);
        printf("\n");
        for(i=0,j=0;i<p;i++,j++)
            c[j]=a[i];
        for(k=0;k<ilb;k++,j++)
            c[j]=b[k];
        for(l=i;l<ila;l++,j++)
            c[j]=a[l];
        c[j]='\0';
        printf("String after is insertion is:- %s",c);
        break;
        }

        case 5: {
        int i,j,k;
        printf("Enter string:- ");
        scanf("%s", a);
        printf("Enter substring to be deleted:- ");
        scanf("%s", b);
        int ila=strlen(a), ilb=strlen(b);
        char* p=strstr(a,b);
        if(p==NULL)
            printf("Substring not found!");
        else
        {
            int index=(p-a);
            for(i=0,j=0;i<index;i++,j++)
                c[j]=a[i];
            i+=ilb;
            for(k=i;a[k]!='\0';k++,j++)
                c[j]=a[k];
            c[j]='\0';
            printf("String after deletion is:- %s",c);
        }
        break;
        }
    }
	printf("\n\n\nDo you want to continue? (y/n):- ");
	fflush(stdin);
	scanf("%c",&key);
	if(key=='y')
	{
		printf("\n\nEnter operation number:- ");
		scanf("%d",&n);
		printf("\n");
	}
	}while(key=='y');
    return 0;
}
