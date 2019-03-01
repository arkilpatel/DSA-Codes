#include<iostream>
#include<cmath>

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

struct node *insert(struct node *root,int data)
{
	if(root == NULL)
		return newNode(data);
	
	if(data<root->key)
	{
		root->left = insert(root->left,data);
		if(root->height<(1+(root->left)->height))
		{
			root->height = 1+(root->left)->height;
		}
	}
	else
	{
		root->right = insert(root->right,data);
		if(root->height<(1+(root->right)->height))
		{
			root->height = 1+(root->right)->height;
		}
	}
	
	return root;
}

bool isBalanced(struct node *root)
{
  if(root==NULL)
    return true;
  int slope;
  if(root->left == NULL)
  {
  	if(root->right == NULL)
  		return true;
  	else
  		slope = root->right->height;
  }
  if(root->right == NULL)
  	slope = root->left->height;
  if(root->left!=NULL && root->right!=NULL)
 	slope = abs((root->left)->height - (root->right)->height);
  if(slope>1)
  	return false;
  if(!isBalanced(root->left))
  	return false;
  return isBalanced(root->right);
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int arr[n];
		struct node *root;
		root = NULL;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			root = insert(root,arr[i]);		
		}
		if(isBalanced(root))
			cout<<"1";
		else
			cout<<"0";
		cout<<endl;
	}	
	return 0;
}





























