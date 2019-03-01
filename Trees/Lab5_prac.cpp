#include<iostream>

using namespace std;
  
struct node
{
    int key;
    struct node *left, *right;
};
  
struct node *newNode(int item)
{
    struct node *temp = new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

int size(struct node *root)
{
	if (root == NULL)
	    return 0;
    return 1 + size(root->left) + size(root->right);
}
  
void preOrder(struct node *root)
{
  if(root==NULL)
    return;
  cout<<size(root->left)-size(root->right)<<" ";
  preOrder(root->left);
  preOrder(root->right);
}
  
struct node* insert(struct node* node, int key)
{
    if (node == NULL) 
    	return newNode(key);
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
 
    return node;
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
		for(int j=0;j<n;j++)
		{
			cin>>arr[j];
			root = insert(root,arr[j]);
		}
    	preOrder(root);
    	cout<<endl;
    }  
    return 0;
}


	
	
	
	
	
	
	
	
	
	
	
	
