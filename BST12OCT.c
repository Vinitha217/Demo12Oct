

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct BST
{
	int data;
	struct BST *lchild;
	struct BST *rchild;
}node;

node *create( node *root, int key)
{
	node *temp;
	if(root==NULL)
	{
		temp=(node *)malloc(sizeof(node));
		temp->data=key;
		temp->lchild=NULL;
		temp->rchild=NULL;
		root=temp;
	}
	else
	{
		if(key<root->data)
		{
			root->lchild=create(root->lchild, key);
		}
		else
		{
			root->rchild=create(root->rchild, key);
		}
	}
	return root;
}

node * search(node *root, int key)
{
	if(root==NULL)
		return NULL;
	else
	{
		if(root->data==key)
			return root;
		else if(root->data>key)
			return search(root->lchild,key);
		else
			return search(root->rchild,key);
	}
}

node * min(node *root)
{
	if(root==NULL)
		return NULL;
	else
	{
		if(root->lchild==NULL)
			return root;
		else
			return min(root->lchild);
	}
}

node * max(node *root)
{
	if(root==NULL)
		return NULL;
	else
	{
		if(root->rchild==NULL)
			return root;
		else
			return max(root->rchild);
	}
}

void displayBST(node *root)
{
	if(root!=NULL)
	{
		displayBST(root->lchild);
		printf("%d ", root->data);
		displayBST(root->rchild);
	}

}

void main()
{
	int x, ch, ans=1;
	node *root, *temp;
	clrscr();
	do
	{

		printf("\n1.Create\n2.Search\n3.Min Node\n4.Max Node\n5.Display\n\nEnter choice: ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				{
					printf("\nEnter Data: ");
					scanf("%d", &x);

					root=create(root,x);
					break;
				}
			case 2:
				{
					printf("\nEnter the data to search: ");
					scanf("%d", &x);
					temp= search(root,x);
					if(temp==NULL)
						printf("\nData NOT found!");
					else
						printf("\nData FOUND");

					break;
				}
			case 3:
				{
					temp=min(root);
					printf("\n\nTHE MIN ELEMENT IS: %d", temp->data);

					break;
				}
			case 4:
				{
					temp=max(root);
					printf("\n\nTHE MAX ELEMENT IS: %d", temp->data);

					break;
				}
			case 5:
				{
					printf("\n\nTHE DATA IS: ");
					displayBST(root);

					break;
				}


			default: printf("\n\n**WRONG CHOICE**");

		}

		printf("\nWant to enter more (0/1) : ");
		scanf("%d", &ans);
	}while(ans==1);
	getch();

}
