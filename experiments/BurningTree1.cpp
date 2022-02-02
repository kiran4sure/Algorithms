#include<iostream>
#include<queue>
#include<vector>

using namespace std;


struct node
{
    int key;
    node *left, *right;

    node(int val)
    {
        this->key = val;
        left = right = nullptr;
    }
};


int burnTreeUtil(node *root, int target, queue<node*> &q, vector<vector<int>> &lst)
{
    if(root == nullptr)
    { 
        return 0;
    }

    if(root->key == target)
    {
        // cout << root->key << endl;
        vector<int> v;
        v.push_back(root->key);
        lst.push_back(v);

        if(root->left)
            q.push(root->left);

        if(root->right)
            q.push(root->right);

        return 1;
    }

    int a = burnTreeUtil(root->left, target, q, lst);

    if(a)
    {
        int size = q.size();
        vector<int> v;
        while(size--)
        {
            node *temp = q.front();
            q.pop();

            // cout << temp->key << ", ";
            v.push_back(temp->key);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        
        if(root->right)
            q.push(root->right);
        // cout << root->key << endl;
        v.push_back(root->key);
        lst.push_back(v);

        return a+1;
    }

    int b = burnTreeUtil(root->right, target, q, lst);
    if(b)
    {
        int size = q.size();
        vector<int> v;
        while(size--)
        {
            node *temp = q.front();
            q.pop();

            // cout << temp->key << ", ";
            v.push_back(temp->key);

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }

        // cout << root->key << endl;
        v.push_back(root->key);

        if(root->left)
            q.push(root->left);

        lst.push_back(v);

        return b+1;
    }
    return 0;
}


int burnTree(node *root, int target, vector<vector<int>> &lst)
{
    queue<node*> q;

    int time = burnTreeUtil(root, target, q, lst);  
    // While loop runs unless queue becomes empty
	while (!q.empty()) {
		int qSize = q.size();
        time++;
            vector<int> v;
		while (qSize--) {
			node* temp = q.front();
			q.pop();

			// Printing of burning nodes
			// cout << temp->key;
            v.push_back(temp->key);
			// Insert left child in a queue, if exist
			if (temp->left != NULL) {
				q.push(temp->left);
			}
			// Insert right child in a queue, if exist
			if (temp->right != NULL) {
				q.push(temp->right);
			}

			// if (q.size())
			// 	cout << " , ";
            if(!qSize)
            {
                lst.push_back(v);
            }
		}
		// cout << endl;
	} 
    return time; 
}



int main()
{
   /*	 10
		/    \
	  12       13
			 /     \
		   14       15
		 /    \     /  \
	   21     22   23  24
      /  \
    101   102
    /  \
  110  111
	Let us create Binary Tree as shown
		above */

	node* root = new node(10);
	root->left = new node(12);
	root->right = new node(13);

	root->right->left = new node(14);
	root->right->right = new node(15);

	root->right->left->left = new node(21);
	root->right->left->right = new node(22);
	root->right->right->left = new node(23);
	root->right->right->right = new node(24);
  root->right->left->left->left = new node(101);
  root->right->left->left->right = new node(102);
  root->right->left->left->left->left = new node(110);
  root->right->left->left->left->right = new node(111);
	int targetNode = 14;

    vector<vector<int>> lst;

	// Function call
	int time = burnTree(root, targetNode, lst);

   cout << "time = " << time << endl;
    for(auto v: lst)
    {
        for(int i=0; i<v.size(); i++)
        {
            cout << v[i];
            if(i < v.size()-1)
                cout << ", ";
        }
        cout << endl;
    }

	return 0;
}