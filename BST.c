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
struct node *par = NULL;
struct node *loc = NULL;

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

struct node* Find(struct node *root, int key)
{
	par = loc = NULL;
	curr = root;
	
	while (curr)
	{
		if (curr->data == key)
		{
			loc = curr;
			printf("Key found!\n");
			return loc;
		}
		
		par = curr;
		
		if (curr->data < key)
			curr = curr->right;
		
		else
			curr = curr->left;
	}
	
	printf("Key not found.\n");
	return NULL;
}

void Insert(struct node **root, struct node *curr)
{
	if (*root == NULL)
	{
		*root = curr;
		return;
	}
	
	if ((*root)->data < curr->data)
		Insert(&(*root)->right, curr);
	
	else
		Insert(&(*root)->left, curr);
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

void Delete(struct node **root, int key)
{
	struct node *temp;
	
	temp = Find(*root, key);
	
	if (temp == NULL)
		return;

	if (temp->left == NULL && temp->right == NULL)
	{
		if (par == NULL)
		{
			*root = NULL;
			return;
		}
		
		if (par->left == temp)
			par->left = NULL;
		else
			par->right = NULL;
		
		free(temp);
	}
	
	else if (temp->left != NULL && temp->right == NULL)
	{
		if (par == NULL)
		{
			(*root)->data = (*root)->left->data;
			temp = (*root)->left;
			(*root)->left = NULL;
		}
		
		else if (par->left == temp)
			par->left = temp->left;
		else
			par->right = temp->left;
		
		free(temp);
	}
	
	else if (temp->left == NULL && temp->right != NULL)
	{
		if (par == NULL)
		{
			(*root)->data = (*root)->right->data;
			temp = (*root)->right;
			(*root)->right = NULL;
		}
		
		else if (par->left == temp)
			par->left = temp->right;
		else
			par->right = temp->right;
		
		free(temp);
	}
	
	else
	{
		par = temp;
		curr = temp->right;
		
		while (curr->left != NULL)
		{
			par = curr;
			curr = curr->left;
		}
		
		temp->data = curr->data;
		
		if (par->left == curr)
			par->left = NULL;
		
		else
			par->right = NULL;
		
		free(curr);
	}
}

void Min()
{
	curr = root;
	
	if (curr == NULL)
	{
		printf("Binary Search Tree is Empty.\n");
		return;
	}
	
	while (curr->left != NULL)
		curr = curr->left;
	
	printf("The Minimum Element in Binary Search Tree is %d.\n", curr->data);
}

void Max()
{
	curr = root;
	
	if (curr == NULL)
	{
		printf("Binary Search Tree is Empty.\n");
		return;
	}
	
	while (curr->right != NULL)
		curr = curr->right;
	
	printf("The Maximum Element in Binary Search Tree is %d.\n", curr->data);
}

int Height(struct node *root)
{
	if (root == NULL)
		return -1;
	
	return Height(root->left) > Height(root->right) ? Height(root->left)+1 : Height(root->right)+1;
}

int main()
{
	int n, key;
	
	do
	{
		printf("1. Traverse Binary Search Tree in Preorder\n");
		printf("2. Traverse Binary Search Tree in Inorder\n");
		printf("3. Traverse Binary Search Tree in Postorder\n");
		printf("4. Insert Node in Binary Search Tree\n");
		printf("5. Delete Node in Binary Search Tree\n");
		printf("6. Find Minimum Element in Binary Search Tree\n");
		printf("7. Find Maximum Element in Binary Search Tree\n");
		printf("8. Find Height of Binary Search Tree\n");
		printf("9. Find Element in Binary Search Tree\n");
		printf("0. Exit\n");
		printf("Input: ");
		scanf("%d", &n);
		
		switch (n)
		{
			case 1: Preorder(root); printf("\n"); break;
			case 2: Inorder(root); printf("\n"); break;
			case 3: Postorder(root); printf("\n"); break;
			case 4: Create(); break;
			case 5: printf("Enter Element to Delete: ");
					scanf("%d", &key);
					Delete(&root, key);
					printf("Element %d deleted.\n", key);
					break;
			case 6: Min(); break;
			case 7: Max(); break;
			case 8: printf("The Height of the Binary Search Tree is %d.\n", Height(root)); break;
			case 9: printf("Enter Element to Search: ");
					scanf("%d", &key);
					Find(root, key);
					break;
			case 0: break;
			default: printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}