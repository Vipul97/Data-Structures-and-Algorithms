#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node *p;
	struct node *left;
	struct node *right;
};

struct node *x = NULL;
struct node *y = NULL;
struct node *z = NULL;
struct node *root = NULL;

void InorderTreeWalk(struct node *x)
{
	if (x != NULL)
	{
		InorderTreeWalk(x->left);
		printf("%d ", x->key);
		InorderTreeWalk(x->right);
	}
}

void PreorderTreeWalk(struct node *x)
{
	if (x != NULL)
	{
		printf("%d ", x->key);
		PreorderTreeWalk(x->left);
		PreorderTreeWalk(x->right);
	}
}

void PostorderTreeWalk(struct node *x)
{
	if (x != NULL)
	{
		PostorderTreeWalk(x->left);
		PostorderTreeWalk(x->right);
		printf("%d ", x->key);
	}
}

struct node *TreeSearch(struct node *x, int k)
{
	if (x == NULL || k == x->key)
		return x;

	if (k < x->key)
		return TreeSearch(x->left, k);

	return TreeSearch(x->right, k);
}

struct node *IterativeTreeSearch(struct node *x, int k)
{
	while (x != NULL && k != x->key)
		if (k < x->key)
			x = x->left;
		else
			x = x->right;

	return x;
}

struct node *TreeMinimum(struct node *x)
{
	while (x->left != NULL)
		x = x->left;

	return x;
}

struct node *TreeMaximum(struct node *x)
{
	while (x->right != NULL)
		x = x->right;

	return x;
}

struct node *TreeMinimumRecursive(struct node *x)
{
	if (x->left != NULL)
		return TreeMinimumRecursive(x->left);

	return x;
}

struct node *TreeMaximumRecursive(struct node *x)
{
	if (x->right != NULL)
		return TreeMaximumRecursive(x->right);

	return x;
}

struct node *TreeSuccessor(struct node *x)
{
	if (x->right != NULL)
		return TreeMinimum(x->right);

	struct node *y = x->p;

	while (y != NULL && x == y->right)
	{
		x = y;
		y = y->p;
	}

	return y;
}

struct node *TreePredecessor(struct node *x)
{
	if (x->left != NULL)
		return TreeMaximum(x->left);

	struct node *y = x->p;

	while (y != NULL && x == y->left)
	{
		x = y;
		y = y->p;
	}

	return y;
}

void TreeInsert(struct node *z)
{
	y = NULL;
	x = root;

	while (x != NULL)
	{
		y = x;

		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	z->p = y;

	if (y == NULL)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
}

void Transplant(struct node *u, struct node *v)
{
	if (u->p == NULL)
		root = v;
	else if (u == u->p->left)
		u->p->left = v;
	else
		u->p->right = v;

	if (v != NULL)
		v->p = u->p;
}

void TreeDelete(struct node *z)
{
	if (z->left == NULL)
		Transplant(z, z->right);
	else if (z->right == NULL)
		Transplant(z, z->left);
	else
	{
		y = TreeMinimum(z->right);

		if (y->p != z)
		{
			Transplant(y, y->right);
			y->right = z->right;
			y->right->p = y;
		}

		Transplant(z, y);
		y->left = z->left;
		y->left->p = y;
	}
}

int main()
{
	int n, k;

	do
	{
		printf("1. Inorder Tree Walk\n");
		printf("2. Preorder Tree Walk\n");
		printf("3. Postorder Tree Walk\n");
		printf("4. Search\n");
		printf("5. Find Minimum\n");
		printf("6. Find Maximum\n");
		printf("7. Find Successor\n");
		printf("8. Find Predecessor\n");
		printf("9. Insert\n");
		printf("10. Delete\n");
		printf("0. Exit\n");
		printf("Input: ");
		scanf("%d", &n);

		switch (n)
		{

		case 1:
			if (root)
				InorderTreeWalk(root);
			else
				printf("Tree is Empty.");
			printf("\n");
			break;
		case 2:
			if (root)
				PreorderTreeWalk(root);
			else
				printf("Tree is Empty.");
			printf("\n");
			break;
		case 3:
			if (root)
				PostorderTreeWalk(root);
			else
				printf("Tree is Empty.");
			printf("\n");
			break;
		case 4:
			printf("Enter Key to Search: ");
			scanf("%d", &k);
			if (TreeSearch(&x, k) != NULL)
				printf("Key Found.\n");
			else
				printf("Key Not Found.\n");

			break;
		case 5:
			if (root)
				printf("%d", TreeMinimum(root)->key);
			else
				printf("Tree is Empty");
			printf("\n");
			break;
		case 6:
			if (root)
				printf("%d", TreeMaximum(root)->key);
			else
				printf("Tree is Empty");
			printf("\n");
			break;
		case 7:
			if (root)
			{
				printf("Enter Key: ");
				scanf("%d", &k);
				printf("%d", TreeSuccessor(TreeSearch(root, k))->key);
			}
			else
				printf("Tree is Empty");
			printf("\n");
			break;
		case 8:
			if (root)
			{
				printf("Enter Key: ");
				scanf("%d", &k);
				printf("%d\n", TreePredecessor(TreeSearch(root, k))->key);
			}
			else
				printf("Tree is Empty");
			printf("\n");
			break;
		case 9:
			z = (struct node *)malloc(sizeof(struct node));
			printf("Enter Key: ");
			scanf("%d", &z->key);
			TreeInsert(z);
			break;
		case 10:
			if (root)
			{
				printf("Enter Key: ");
				scanf("%d", &k);
				if (TreeSearch(root, k) != NULL)
				{
					TreeDelete(TreeSearch(root, k));
					printf("%d deleted.", k);
				}
				else
					printf("Key not Found.");
			}
			else
				printf("Tree is Empty");
			printf("\n");
			break;
		case 0:
			break;
		default:
			printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}
