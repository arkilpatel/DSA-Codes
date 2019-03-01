#include<iostream>
#include<algorithm>

using namespace std;

struct node
{
	int key;
	int height;
	node *left;
	node *right;
};

struct node *newNode(int data)
{
	struct node *temp = new node;
	temp->key = data;
	temp->height = 1;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int height(struct node *root)
{
	if(root == NULL)
		return 0;
	return 1 + max(height(root->left),height(root->right));
}

int getSlope(struct node *root)
{
	if(root == NULL)
		return 0;
	if(root->left == NULL)
	{
		if(root->right == NULL)
			return 0;
		return (0-root->right->height);
	}
	if(root->right == NULL)
		return root->left->height;
	return (root->left->height - root->right->height);
}

struct node *leftRotate(struct node *v)
{
	int ht1=0,ht2=0,ht3=0;
	
	struct node *u,*t2;
	u = v->right;
	t2 = u->left;
	
	if(v->left!=NULL)
		ht1 = v->left->height;
	if(u->left!=NULL)
		ht2 = u->left->height;
	if(u->right!=NULL)
		ht3 = u->right->height;
		
	u->left = v;
	v->right = t2;
	
	v->height = max(ht1,ht2)+1;
	u->height = max(ht3,v->height)+1;
	
	return root;	
}

struct node *rightRotate(struct node *u)
{
	int ht1=0,ht2=0,ht3=0;
	
	struct node *v,*t2;
	v = u->left;
	t2 = v->right;
	
	if(v->left!=NULL)
		ht1 = v->left->height;
	if(v->right!=NULL)
		ht2 = v->right->height;
	if(u->right!=NULL)
		ht3 = u->right->height;
	
	v->right = u;
	u->left = t2;
	
	u->height = max(ht2,ht3)+1;
	v->height = max(ht1,u->height)+1;
	
	return root;	
}

struct node *insert(struct node *root,int data)
{
	if(root == NULL)
		return newNode(data);
	else
	{
		if(data<root->key)
		{
			root->left = insert(root->left,data);
			if(root->height<1+root->left->height)
			{
				root->height = 1+root->left->height;
			}
		}
		else
		{
			root->right = insert(root->right,data);
			if(root->height<1+root->right->height)
			{
				root->height = 1+root->right->height;
			}
		}
	}
	
	int slope = getSlope(root);
	
	if(root->left!=NULL)
	{
		if(slope>1 && data<root->left->key)
		{
			return rightRotate(root);
		}
		if(slope>1 && data>root->left->key)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}
	
	if(root->right!=NULL)
	{
		if(slope<-1 && data>root->right->key)
		{
			return leftRotate(root);
		}
		if(slope<-1 && data<root->right->key)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	}
	
	return root;	
}

struct node *remove(struct node *root,int data)
{
	if(root == NULL)
		return root;
		
	if(data<root->key)
		root->left = remove(root->left,data);
	else if(data>root->key)
		root->right = remove(root->right,data);
	else
	{
		if((root->left == NULL) || (root->right == NULL))
		{
			struct node *temp;
			if(root->left == NULL)
				temp = root->right;
			else
				temp = root->left;
				
			if(temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			
			delete temp;
		}
		else
		{
			struct node *temp = root->right;
			while(temp!=NULL)
			{
				temp = temp->left;
			}
			
			root->key = temp->key;
			
			root->right = remove(root->right,temp->key);
		}
	}
	
	if(root == NULL)
		return root;
	
	root->height = 1+max(height(root->left),height(root->right));
	
	int slope = getSlope(root);
	
	if(root->left != NULL)
	{
		if(slope>1 && getSlope(root->left)>=0)
		{
			return rightRotate(root);
		}
		if(slope>1 && getSlope(root->left)<0)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}
	
	if(root->right != NULL)
	{
		if(slope<-1 && getSlope(root->right)<=0)
		{
			return leftRotate(root);
		}
		if(slope<-1 && getSlope(root->right)>0)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	}
	
	return root;	
}







































