#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;
struct node *curr = NULL;

void Preorder(struct node *root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		Preorder(root->left);
		Preorder(root->right);
	}
}

void Inorder(struct node *root)
{
	if (root != NULL)
	{
		Inorder(root->left);
		printf("%d ", root->data);
		Inorder(root->right);
	}
}

void Postorder(struct node *root)
{
	if (root != NULL)
	{
		Postorder(root->left);
		Postorder(root->right);
		printf("%d ", root->data);
	}
}

void Iter(struct node *root)
{
	struct node *pre;
	
	if (root == NULL)
		return; 
	
	curr = root;
	
	while (curr)
	{                 
		if (curr->left == NULL)
		{
			printf("%d ", curr->data);
			curr = curr->right;      
		}    
		
		else
		{
			pre = curr->left;
			
			while (pre->right != NULL && pre->right != curr)
				pre = pre->right;
			
			if (pre->right == NULL)
			{
				pre->right = curr;
				curr = curr->left;
			}
			
			else 
			{
				pre->right = NULL;
				printf("%d ",curr->data);
				curr = curr->right;      
			}
		}
	}
}

void Insert(struct node **root, struct node *curr)
{
	if (*root == NULL)
		*root = curr;
	
	else
	{
		int n;
		
		printf("1. Insert at left node\n");
		printf("2. Insert at right node\n");
		printf("Input: ");
		scanf("%d", &n);
		
		if (n == 1)
			if ((*root)->left == NULL)
				(*root)->left = curr;
			else
				Insert(&(*root)->left, curr);
		
		else if (n == 2)
			if ((*root)->right == NULL)
				(*root)->right = curr;
			else
				Insert(&(*root)->right, curr);
	}
}

void Create()
{
	curr = (struct node*)malloc(sizeof(struct node));
	
	if (curr == NULL)
	{
		printf("Error.\n");
		return;
	}
	
	printf("Enter Data: ");
	scanf("%d", &curr->data);
	
	curr->left = NULL;
	curr->right = NULL;
	
	Insert(&root, curr);
}

int main()
{
	int n;
	
	do
	{
		printf("1. Traverse Binary Tree in Preorder\n");
		printf("2. Traverse Binary Tree in Inorder\n");
		printf("3. Traverse Binary Tree in Postorder\n");
		printf("4. Traverse Binary Tree Iteratively\n");
		printf("5. Insert Node in Binary Tree\n");
		printf("0. Exit\n");
		printf("Input: ");
		scanf("%d", &n);
		
		switch (n)
		{
			case 1: Preorder(root); printf("\n"); break;
			case 2: Inorder(root); printf("\n"); break;
			case 3: Postorder(root); printf("\n"); break;
			case 4: Iter(root); printf("\n"); break;
			case 5: Create(); break;
			case 0: break;
			default: printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}