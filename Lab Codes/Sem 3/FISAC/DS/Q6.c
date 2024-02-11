#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node* left;
    int data;
    struct node* right;
};
struct node* head=NULL;

struct node* findNode(int val)
{
    if(head==NULL) return NULL;
    else
    {
        struct node* Stack[100];
        int top=-1;
        struct node* current=head;
        while(current!=NULL || top>-1)
        {
            while(current!=NULL)
            {
                Stack[++top]=current;
                if(current->data==val) return current;
                current=current->left;
            }
            current=Stack[top--];
            current=current->right;
        }
    }
}

void insertNode(int val, int parent, int dir)
{
    if(parent==-1 && dir==0)
    {
        if(head==NULL)
        {
            struct node* temp=(struct node*)malloc(sizeof(struct node));
            temp->data=val;
            temp->left=NULL;
            temp->right=NULL;
            head=temp;
        }
        else printf("Tree is not empty! Cannot insert as root!\n");
        return;
    }
    struct node* loc=findNode(parent);
    if(loc==NULL)
    {
        printf("Parent not found!\n");
        return;
    }
    if(dir==1)
    {
        if(loc->left==NULL)
        {
            struct node* temp=(struct node*)malloc(sizeof(struct node));
            temp->data=val;
            temp->left=temp->right=NULL;
            loc->left=temp;
        }
        else printf("Not Empty! Cannot insert!\n");
    }
    else if(dir==2)
    {
        if(loc->right==NULL)
        {
            struct node* temp=(struct node*)malloc(sizeof(struct node));
            temp->data=val;
            temp->left=temp->right=NULL;
            loc->right=temp;
        }
        else printf("Not Empty! Cannot insert!\n");
    }
    else printf("Parent not found!\n");
}

void preorder()
{
    if(head==NULL) printf("Empty!\n");
    else
    {
        struct node* Stack[100];
        int top=-1;
        Stack[++top]=head;
        while(top>-1)
        {
            struct node* current=Stack[top--];
            printf("%d ",current->data);
            if(current->right!=NULL) Stack[++top]=current->right;
            if(current->left!=NULL) Stack[++top]=current->left;
        }
        printf("\n");
    }
}

void levelOrder()
{
    if(head==NULL) return;
    struct node* queue[100];
    int front = 0,rear = 0;
    queue[rear++] = head;

    while (front < rear) {
        struct node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

int main()
{
    insertNode(8,-1,0);
    insertNode(3,8,1);
    insertNode(10,8,2);
    insertNode(1,3,1);
    insertNode(6,3,2);
    insertNode(14,10,2);
    insertNode(13,14,1);
    insertNode(4,6,1);
    insertNode(7,6,2);
    printf("Preorder = ");
    preorder();
    printf("Level order = ");
    levelOrder();
    return 0;
}
