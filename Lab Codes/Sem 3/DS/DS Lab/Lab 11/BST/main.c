#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* insert(struct Node* root, int key)
{
    if(root==NULL)
    {
        struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->key=key;
        newNode->left=newNode->right=NULL;
        return newNode;
    }
    if(key<root->key) root->left=insert(root->left, key);
    else if(key>root->key) root->right=insert(root->right, key);
    return root;
}

struct Node* findMinValueNode(struct Node* node)
{
    struct Node* current;
    for(current=node;current->left!=NULL;current=current->left);
    return current;
}

struct Node* deleteNode(struct Node* root,int key)
{
    if(root==NULL) return root;
    if(key<root->key) root->left=deleteNode(root->left, key);
    else if(key>root->key) root->right=deleteNode(root->right, key);
    else
    {
        if(root->left == NULL)
        {
            struct Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)\
        {
            struct Node* temp=root->left;
            free(root);
            return temp;
        }
        struct Node* temp=findMinValueNode(root->right);
        root->key=temp->key;
        root->right=deleteNode(root->right,temp->key);
    }
    return root;
}

struct Node* search(struct Node* root,int key)
{
    if(root==NULL||root->key==key) return root;
    if(key<root->key) return search(root->left,key);
    return search(root->right,key);
}

void inorderTraversal(struct Node* root)
{
    if(root!=NULL)
    {
        inorderTraversal(root->left);
        printf("%d ",root->key);
        inorderTraversal(root->right);
    }
}

int main()
{
    struct Node* root=NULL;
    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,70);
    root=insert(root,60);
    root=insert(root,80);
    printf("In-order traversal: ");
    inorderTraversal(root);
    root=deleteNode(root,40);
    printf("\nDeleted %d\n",40);
    printf("In-order traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");
    if(search(root,30)) printf("%d found in the BST.\n",30);
    else printf("%d not found in the BST.\n",30);
    return 0;
}
