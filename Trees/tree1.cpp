#include<iostream>
#include<queue>
#include <climits>

using namespace std;

typedef struct Node
{
	int data;
	Node *left;
	Node *right;
	
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
} Node;

Node *levelOrderInsert(int arr[],int n)
{
	Node *root = new Node(arr[0]);
	queue<pair<Node*,int> > q;
	q.push({root,0});
	
	while(!q.empty())
	{
		pair<Node*,int> p = q.front();
		
		if(2*p.second + 1 < n)
		{
			p.first->left = new Node(arr[2*p.second + 1]);
			q.push({p.first->left,2*p.second + 1});
		}
		if(2*p.second + 2 < n)
		{
			p.first->right = new Node(arr[2*p.second + 2]);
			q.push({p.first->right,2*p.second + 2});
		}
		q.pop();
	}
	return root;
}

void preOrder(Node *root) // Root,left subtree,right subtree
{
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node *root) // left subtree,Root,right subtree
{
	if(root == NULL)
		return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void postOrder(Node *root) // left subtree,right subtree,Root
{
	if(root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

void rightViewUtil(Node *root,int h,int &minh)
{
	if(root == NULL)
		return;
	if(minh<h)
	{
		minh = h;
		cout<<root->data<<" ";
	}
	rightViewUtil(root->right,h+1,minh);
	rightViewUtil(root->left,h+1,minh);
}

void rightView(Node *root)
{
	int minh = -1;
	rightViewUtil(root,0,minh);
	cout<<endl;
}

void bottomViewUtil(Node *root,int hd,int &minhd){
  if(root==NULL)
    return;
  bottomViewUtil(root->left,hd-1,minhd);
  if(hd>minhd){
    minhd = hd;
    cout<<root->data<<" ";
  }
  bottomViewUtil(root->right,hd+1,minhd);
}

void bottomView(Node *root){
  int minhd=INT_MIN;
  bottomViewUtil(root,0,minhd);
  cout<<endl;
}

int main()
{
	int arr[8] = {25,8,22,6,3,4,20,5};
	
	Node *root = levelOrderInsert(arr, 8);
	
	cout<<"Bottom View: ";
	bottomView(root);
	
	return 0;
}




























































