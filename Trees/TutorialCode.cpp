#include <iostream>
#include <stack>
#include <queue>
#include <climits>
#include <vector>
#include <map>

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
}Node;

Node *levelOrderInsert(int arr[], int n)
{
  Node *root = new Node(arr[0]);
  queue<pair<Node*, int> > q;
  q.push({root, 0});
  while (!q.empty()) {
    pair<Node*, int> p = q.front();
    if (2*p.second + 1 < n) {
      p.first->left = new Node(arr[2*p.second + 1]);
      q.push({p.first->left, 2*p.second + 1});
    }
    if (2*p.second + 2 < n) {
      p.first->right = new Node(arr[2*p.second + 2]);
      q.push({p.first->right, 2*p.second + 2});
    }
    q.pop();
  }
  return root;
}

void preOrder(Node *root)
{
  if(root==NULL)
    return;
  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(Node *root)
{
  if(root==NULL)
    return;
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}

void postOrder(Node *root){
  if(root==NULL)
    return;
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<<" ";
}

void leftViewUtil(Node *root,int h,int &minh){
  if(root==NULL)
    return;
  if(h>minh){
    minh=h;
    cout<<root->data<<" ";
  }
  leftViewUtil(root->left,h+1,minh);
  leftViewUtil(root->right,h+1,minh);
}

void leftView(Node *root){
  int minh=-1;
  leftViewUtil(root,0,minh);
  cout<<endl;
}

void spiral(Node *root){
  stack<Node*> st0rl,st1lr;
  if(root==NULL)
    return;
  int flag=0;
  st0rl.push(root);
  while((!flag && !st0rl.empty()) || (flag && !st1lr.empty())){
    if(!flag){
      while(!st0rl.empty()){
        Node *n = st0rl.top();
        st0rl.pop();
        cout<<n->data<<" ";
        if(n->right)
          st1lr.push(n->right);
        if(n->left)
          st1lr.push(n->left);
      }
      flag=!flag;
    }
    else{
      while(!st1lr.empty()){
        Node *n = st1lr.top();
        st1lr.pop();
        cout<<n->data<<" ";
        if(n->left)
          st0rl.push(n->left);
        if(n->right)
          st0rl.push(n->right);
      }
      flag=!flag;
    }
  }
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

void verticalview(struct Node* root){
   queue<pair<struct Node *,int> > q;
   map<int,vector<int> > m;
   q.push(make_pair(root,0));

   while(q.empty() == false){
      struct Node *temp = q.front().first;
      int hori = q.front().second;
      q.pop();
      m[hori].push_back(temp->data);
      if(temp->left)
        q.push(make_pair(temp->left,hori-1));
      if(temp->right)
        q.push(make_pair(temp->right,hori+1));
   }

   map<int,vector<int> > :: iterator it;
   for(it = m.begin();it!=m.end();it++){
     vector<int> t = it->second;
     for(int i=0;i<t.size();i++){
      cout<<t[i]<<" ";
     }
     //cout<<endl;
   }
   cout<<endl;
}


int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  Node *root = levelOrderInsert(arr, n);
  cout<<"Spiral View : ";
  spiral(root);
  cout<<"Bottom View : ";
  bottomView(root);
  cout<<"Left View : ";
  leftView(root);
  cout<<"Vertical Traversal : ";
  verticalview(root);
  return 0;
}
