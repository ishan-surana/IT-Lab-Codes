#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node* left;
    int data;
    struct node* right;
}node;
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

int parentNode(int val)
{
    int parent;
    if(head==NULL) printf("Empty tree!\n");
    else if(head->data==val) printf("Value is head! No parent!\n");
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
                if((current->left!=NULL&&current->left->data==val)||(current->right!=NULL&&current->right->data==val))
                    parent=current->data;
                current=current->left;
            }
            current=Stack[top--];
            current=current->right;
        }
    }
    return parent;
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
            struct node* temp=(struct node*)malloc(sizeof(node));
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
            struct node* temp=(struct node*)malloc(sizeof(node));
            temp->data=val;
            temp->left=temp->right=NULL;
            loc->right=temp;
        }
        else printf("Not Empty! Cannot insert!\n");
    }
    else printf("Parent not found!\n");
}

void inorder()
{
    if(head==NULL) printf("Empty!\n");
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
                current=current->left;
            }
            current=Stack[top--];
            printf("%d ",current->data);
            current=current->right;
        }
        printf("\n");
    }
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

void ancestor(int val)
{
    if(val==head->data)
    {
        printf("%d ",head->data);
        return;
    }
    ancestor(parentNode(val));
    printf("%d ", val);
}

int leaves()
{
    int count=0;
    if(head==NULL) printf("Empty!\n");
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
                if(current->left==NULL && current->right==NULL) count++;
                current=current->left;
            }
            current=Stack[top--];
            current=current->right;
        }
    }
    return count;
}


/*
void parent(int val)
{
    if(head==NULL) printf("Empty!\n");
    else if(head->data==val) printf("Val is Head. No Parent!\n");
    else if(head->left->data==val || head->right->data==val) printf("Parent is %d\n",head->data);
    else
    {

    }
}
*/
//void createNode(int val, node* parent)

int main()
{
    inorder();
    insertNode(1,-1,0);
    inorder();
    insertNode(2,1,1);
    inorder();
    insertNode(3,1,2);
    inorder();
    insertNode(4,2,1);
    inorder();
    insertNode(5,2,2);
    inorder();
    insertNode(6,3,1);
    inorder();
    printf("Parent node = %d\n",parentNode(5));
    ancestor(5);
    printf("No. of Leaf nodes = %d\n",leaves());
    insertNode(7,3,2);
    inorder();
    printf("Leaf nodes = %d\n",leaves());
    inorder();
    preorder();
    return 0;
}
