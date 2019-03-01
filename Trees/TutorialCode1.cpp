    #include <iostream>
    #include <stack>
    #include <queue>
    using namespace std;
     
    typedef struct Node
    {
      int data;
      Node *left, *right;
      Node (int data)
      {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
      }
    } Node;
     
    void preOrderIterative(Node *root)
    {
      if (root == NULL)
        return ;
      stack<Node *> S;
      S.push(root);
      while (!S.empty()) {
        Node *p = S.top();
        S.pop();
        cout << p->data << " " << flush;
        if (p->right != NULL)
          S.push(p->right);
        if (p->left != NULL)
          S.push(p->left);
      }
      cout << endl;
    }
     
    void inOrderIterative(Node *root)
    {
      if (root == NULL)
        return ;
      stack<Node *> S;
      bool done = false;
      Node *curr = root;
      while (!done) {
        if (curr != NULL) {
          S.push(curr);
          curr = curr->left;
        }
        else {
          if (!S.empty()) {
            Node *p = S.top();
            S.pop();
            cout << p->data << " " << flush;
            curr = p->right;
          }
          else
            done = true;
        }
      }
      cout << endl;
    }
     
    void levelOrder(Node *root)
    {
      if (root == NULL)
        return ;
      queue<Node *> q;
      q.push(root);
      q.push(NULL);
      while (!q.empty()) {
        Node *p = q.front();
        q.pop();
        if (p != NULL) {
          cout << p->data << " " << flush;
          if (p->left != NULL)
            q.push(p->left);
          if (p->right != NULL)
            q.push(p->right);
        }
        else {
          cout << endl;
          if (!q.empty())
            q.push(NULL);
        }
      }
    }
    /*
    Node *levelOrderInsert(int arr[], int n)
    {
      if (n == 0)
        return NULL;
      Node *root = new Node(arr[0]);
      queue<pair<Node*, int>> q;
      q.push({root, 0});
      while (!q.empty()) {
        pair<Node*, int> p = q.front();
        q.pop();
        if (2*p.second + 1 < n) {
          p.first->left = new Node(arr[2*p.second + 1]);
          q.push({p.first->left, 2*p.second + 1});
        }
        if (2*p.second + 2 < n) {
          p.first->right = new Node(arr[2*p.second + 2]);
          q.push({p.first->right, 2*p.second + 2});
        }
      }
      return root;
    }*/
     
    Node *levelOrderInsert(int arr[], int n)
    {
      if (n == 0)
        return NULL;
      Node *root = new Node(arr[0]);
      queue<Node *> q;
      q.push(root);
      int idx = 1;
      while (!q.empty()) {
        Node *p = q.front();
        q.pop();
        if (idx < n) {
          p->left = new Node(arr[idx++]);
          q.push(p->left);
        }
        if (idx < n) {
          p->right = new Node(arr[idx++]);
          q.push(p->right);
        }
      }
      return root;
    }
     
    int height(Node *root)
    {
      if (root == NULL)
        return 0;
      return 1 + max(height(root->left), height(root->right));
    }
     
    int size(Node *root)
    {
      if (root == NULL)
        return 0;
      return 1 + size(root->left) + size(root->right);
    }
     
    int depth(Node *root, int data, int d)
    {
      if (root == NULL)
        return -1;
      if (data == root->data)
        return d;
      int d_left = depth(root->left, data, d + 1);
      if (d_left != -1)
        return d_left;
      return depth(root->right, data, d + 1);
    }
     
    void noOfLeafNodes(Node *root, int &cnt)
    {
      if (root == NULL)
        return ;
      if (root->left == NULL && root->right == NULL)
        cnt += 1;
      else {
        noOfLeafNodes(root->left, cnt);
        noOfLeafNodes(root->right, cnt);
      }
    }
     
    bool checkIfIdentical(Node *root1, Node *root2)
    {
      if (root1 == NULL && root2 == NULL)
        return true;
      else if ((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL))
        return false;
      return (root1->data == root2->data) && checkIfIdentical(root1->left, root2->left) && checkIfIdentical(root1->right, root2->right);
    }
     
    bool checkIfMirror(Node *root1, Node *root2)
    {
      if (root1 == NULL && root2 == NULL)
        return true;
      else if ((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL))
        return false;
      return (root1->data == root2->data) && checkIfMirror(root1->left, root2->right) && checkIfMirror(root1->right, root2->left);
    }
     
    bool isBalanced(Node *root)
    {
      if (root == NULL)
        return true;
      int left_height = height(root->left);
      int right_height = height(root->right);
      return abs(left_height - right_height) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
     
    int diameter(Node *root)
    {
      if (root == NULL)
        return 0;
      int left_h = height(root->left);
      int right_h = height(root->right);
      return max(left_h + right_h + 1, max(diameter(root->left), diameter(root->right)));
    }
     
    int main()
    {
      int n;
      cin >> n;
      int *arr = new int[n];
      for(int i=0;i<n;i++) {
        cin >> arr[i];
      }
      Node *root = levelOrderInsert(arr, n);
      preOrderIterative(root);
      inOrderIterative(root);
      levelOrder(root);
      cout << height(root) << endl;
      cout << size(root) << endl;
      int noOfNodesLeaf = 0;
      noOfLeafNodes(root, noOfNodesLeaf);
      cout << noOfNodesLeaf << endl;
      cout << diameter(root) << endl;
      cout << isBalanced(root) << endl;
      return 0;
    }
