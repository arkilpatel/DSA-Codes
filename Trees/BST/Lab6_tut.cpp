#include<iostream>
#include<cmath>
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

bool search_bool (struct node *root,int data)
{
	if(root == NULL)
		return false;
	if(data == root->key)
		return true;
	if(data<root->key)
		return search_bool(root->left,data);
	return search_bool(root->right,data);	
}

struct node *search (struct node *root,int data)
{
	if(root == NULL)
		return root;
	if(data == root->key)
		return root;
	if(data<root->key)
		return search(root->left,data);
	return search(root->right,data);
}

struct node *parent(struct node *root,int data)
{
	if(root == NULL)
		return NULL;
	if(root->key == data)
		return NULL;
	if(data<root->key)
	{
		if(root->left != NULL)
		{
			if(root->left->key == data)
				return root;
			else
				return parent(root->left,data);
		}
	}
	if(data>root->key)
	{	
		if(root->right != NULL)
		{
			if(root->right->key == data)
				return root;
			else
				return parent(root->right,data);
		}
	}
	return NULL;
}

struct node *lca(struct node *root,int a,int b)
{
	if(root == NULL)
		return NULL;
	if(root->key == a || root->key == b)
		return root;
	if((a<root->key && b>root->key) || (b<root->key && a>root->key))
		return root;
	if(a<root->key && b<root->key)
		return lca(root->left,a,b);
	return lca(root->right,a,b);
}

struct node *inorderSuccessor(struct node *root,int data)
{
	struct node *temp = search(root,data);
	
	if(root == NULL || temp == NULL)
		return NULL;
	if(temp->right == NULL)
	{
		if(temp->key<parent(root,temp->key)->key)
			return parent(root,data);
		
		struct node *temp2 = temp;
		temp2 = parent(root,temp->key);
		if(temp2 == NULL)
			return temp;
		
		while(data>temp2->key)
		{
			temp2 = parent(root,temp2->key);
			if(temp2 == NULL)
				return NULL;
		}	
		return temp2;
	}
	
	struct node *right_root = temp->right;
	struct node *least = right_root;
	if (right_root->left == NULL)
	{
		return right_root;
	}
	else
	{
		while(least->left != NULL)
		{
			least = least->left;
		}
		return least;
	}
}

/*
int subtrees_range(struct node *root,int a,int b)
{
	int count = 0,temporary;
	if(a>b)
	{
		temporary = a;
		a = b;
		b = temporary;
	}
	struct node *ta = search(root,a);
	struct node *tb = search(root,b);
	
	if(ta->left
	
}
*/
void remove (struct node *root,int data)
{
	struct node *temp = search(root,data);
	if(temp!=NULL)
	{
		if(temp->right != NULL)
		{
			struct node *right_root = temp->right;
			struct node *secleast = right_root;
			struct node *least = secleast;
			if (right_root->left == NULL)
			{
				temp->key = right_root->key;
				temp->right = right_root->right;
				delete right_root;
			}
			else if(right_root->left->left == NULL)
			{
				least = right_root->left;
				temp->key = least->key;
				right_root->left = least->right;
				delete least;
			}
			else
			{
				while(secleast->left->left != NULL)
				{
					secleast = secleast->left;
				}
				least = secleast->left;
				temp->key = least->key;
				secleast->left = least->right;
				delete least;
			}
		}
		else
		{
			struct node *p = parent(root,temp->key);
			if(temp->key<p->key)
			{
				p->left = temp->left;
				delete temp;
			}
			else
			{
				p->right = temp->left;
				delete temp;
			}
		}
	}	
}
  
struct node* insert(struct node* node, int key)
{
    if (node == NULL) 
    	return newNode(key);
 
    if (key < node->key)
    {
        node->left  = insert(node->left, key);
    }
    else
    {
        node->right = insert(node->right, key);   
 	}
    return node;
}

void preOrder(struct node *root)
{
  if(root==NULL)
    return;
  cout<<root->key<<" ";
  preOrder(root->left);
  preOrder(root->right);
}
  
int main()
{
	int n,ele1,ele2;
	cin>>n;
	int arr[n];
	struct node *root;
	root = NULL;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		root = insert(root,arr[i]);		
	}
	
	preOrder(root);
	
	cout<<"Enter element 1 ";
	cin>>ele1;
	/*
	cout<<"Enter element 2 ";
	cin>>ele2;*/
	
	cout<<inorderSuccessor(root,ele1)->key;
	
//	cout<<lca(root,ele1,ele2)->key;
	
	//remove(root,ele);
	
	//preOrder(root);
	/*
	if(search_bool(root,ele) == true)
		cout<<"true";
	else
		cout<<"false";
		if(is_balanced(root)) cout<<"Tree is balanced"<<endl;
		else cout<<"Tree is not balanced"<<endl;*/
	cout<<endl;
    return 0;
}


	
	
	
	
	
	
	
	
	
	
	
	
