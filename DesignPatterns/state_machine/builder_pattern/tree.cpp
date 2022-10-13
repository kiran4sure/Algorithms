// C++ program for different tree traversals
#include <iostream>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
	int data;
	struct Node *left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void printPostorder(struct Node* node)
{
	if (node == NULL)
		return;

	// first recur on left subtree
	printPostorder(node->left);

	// then recur on right subtree
	printPostorder(node->right);

	// now deal with the node
	cout << node->data << " ";
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout << node->data << " ";

	/* now recur on right child */
	printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node)
{
	if (node == NULL)
		return;

	/* first print data of node */
	cout << node->data << " ";

	/* then recur on left sutree */
	printPreorder(node->left);

	/* now recur on right subtree */
	printPreorder(node->right);
}

struct Node* inorderSuccessor(struct Node* root, int data, int &flag)
{
  	if(root == NULL)
      return root;
  	
  	Node *left = inorderSuccessor(root->left, data, flag);
  	if(left!= NULL)
      return left;
  	if(flag == 1)
    {
      return root;
    }
  	if(root->data == data);
  	{
      flag = 1;
    }
  	return inorderSuccessor(root->right, data, flag);
}

/* Driver program to test above functions*/
int main()
{
	struct Node* root = new Node(20);
	root->left = new Node(9);
	root->right = new Node(25);
	root->left->left = new Node(5);
	root->left->right = new Node(12);
  root->left->right->left = new Node(11);
  root->left->right->right = new Node(14);

	cout << "\nPreorder traversal of binary tree is \n";
	printPreorder(root);

	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);

	cout << "\nPostorder traversal of binary tree is \n";
	printPostorder(root);
  	int data = 9;
  int flag = 0;
  	struct Node *ans = inorderSuccessor(root, data, flag);
	cout << endl <<"inorder successor of "<< data << " = " << ans->data << endl; 
	return 0;
}
