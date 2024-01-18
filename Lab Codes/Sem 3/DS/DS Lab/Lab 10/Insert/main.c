#include <stdio.h>
#include <stdlib.h>

struct BST
{
	int key;
	struct BST *left, *right;
};
struct BST* head=NULL;

struct BST* newNode(int item)
{
	struct BST* temp=(struct BST*)malloc(sizeof(struct BST));
	temp->key=item;
	temp->left=temp->right=NULL;
	return temp;
}

void inorder(struct BST* root)
{
    if(head==NULL) printf("Khatam, tata, byebye!\n");
	if(root!=NULL)
    {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}


struct BST* insert(struct BST* node,int key)
{
	if(node==NULL) return newNode(key);
	if(key<node->key) node->left=insert(node->left,key);
	else node->right=insert(node->right,key);
	return node;
}

struct BST* deleteNode(struct BST* root,int k)
{
	if (root==NULL)
		return root;

	if(root->key>k)
    {
		root->left=deleteNode(root->left,k);
		return root;
	}
	else if(root->key<k)
	{
		root->right=deleteNode(root->right,k);
		return root;
	}

	// If one of the children is empty
	if (root->left==NULL)
    {
		struct BST* temp = root->right;
		free(root);
		return temp;
	}
	else if (root->right == NULL) {
		struct BST* temp = root->left;
		free(root);
		return temp;
	}

	// If both children exist
	else {

		struct BST* succParent = root;

		// Find successor
		struct BST* succ = root->right;
		while (succ->left != NULL) {
			succParent = succ;
			succ = succ->left;
		}

		// Delete successor. Since successor
		// is always left child of its parent
		// we can safely make successor's right
		// right child as left of its parent.
		// If there is no succ, then assign
		// succ->right to succParent->right
		if (succParent != root)
			succParent->left = succ->right;
		else
			succParent->right = succ->right;

		// Copy Successor Data to root
		root->key = succ->key;

		// Delete Successor and return root
		free(succ);
		return root;
	}
}

int main()
{
	/*BST
          40
		/	 \
       20	 60
      / \    / \
	 10 30  50 70 */
	struct BST* root=NULL;
	inorder(root);
	root=insert(root,40);
	head=root;
	root=insert(root,20);
	root=insert(root,10);
	root=insert(root,30);
	root=insert(root,60);
	root=insert(root,50);
    printf("BST = ");
    inorder(root);

	printf("\n\nDelete a Leaf Node: 20\n");
	root = deleteNode(root, 10);
	printf("Modified BST tree after deleting Leaf Node:\n");
	inorder(root);

	printf("\n\nDelete Node with single child: 70\n");
	root = deleteNode(root, 60);
	printf("Modified BST tree after deleting single child Node:\n");
	inorder(root);

	printf("\n\nDelete Node with both child: 50\n");
	root = deleteNode(root, 40);
	printf("Modified BST tree after deleting both child Node:\n");
	inorder(root);

	return 0;
}
