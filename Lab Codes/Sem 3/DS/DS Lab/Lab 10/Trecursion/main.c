#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createBinaryTree()
{
    int data;
    struct Node* root=NULL;
    printf("Enter data for the node (or -1 to terminate): ");
    scanf("%d", &data);
    if(data==-1) return NULL;
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    printf("Enter left child of %d:\n", data);
    root->left=createBinaryTree();
    printf("Enter right child of %d:\n", data);
    root->right=createBinaryTree();
    return root;
}

void inorderTraversal(struct Node* root)
{
    if(root==NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct Node* root)
{
    if(root==NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct Node* root)
{
    if(root==NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main()
{
    struct Node* root=createBinaryTree();
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");
    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");
    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");
    return 0;
}