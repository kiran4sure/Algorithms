/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
#include<iostream>
#include <vector>

using namespace std;

    // Node* arr[100000];

class Solution {

    // int N = 100000;



public:
    Node *_connect(Node *root, int level, vector<Node*> &lst)
    {
        if(root == NULL) return root;

        if(lst.size() < level+1)
            lst.push_back(NULL);

        root->next = NULL;
        if(lst[level] == NULL)
        {
            lst[level] = root;
        }
        else
        {
            lst[level]->next = root;
            lst[level] = root;
        }

        _connect(root->left, level+1, lst);
        _connect(root->right, level+1, lst);

        return root;

    }

     Node* connect(Node* root) {
         vector<Node*> lst;
         lst.push_back(NULL);

        //  for(int i=0; i<100000; i++)
        //  {
        //      arr[i] = NULL;
        //  }

         return _connect(root, 1, lst);
     } 

    // Node* xconnect(Node* root) {
        
    //     if(!root) return root;

    //     queue<Node*> q;
    //     root->next = NULL;
    //     q.push(root);

    //     while(q.size())
    //     {
    //         int size = q.size();
    //         Node *prev = NULL;
    //         Node *current = NULL;
    //         while(size--)
    //         {
    //            if(prev == NULL)
    //            {
    //                prev = q.front();
    //                prev->next = NULL;
    //            }
    //            else
    //            {
    //                current = q.front();
    //                current->next = NULL;
    //                prev->next = current;
    //                prev = current;
    //            }

    //             if(prev->left)
    //                 q.push(prev->left);

    //             if(prev->right)
    //                 q.push(prev->right);
    //             q.pop();
    //         }
    //     }
    //     return root;
    // }
};
// @lc code=end

