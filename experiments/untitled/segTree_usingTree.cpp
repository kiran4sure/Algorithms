//
// Created by Kirankumar Srikanta on 20/6/20.
//
#include<bits/stdc++.h>
#include<cmath>
#include<sstream>
#include <iomanip>
using std::left;
using std::right;
using std::setw;
using namespace std;


struct segTreeNode{
    int start;
    int end;
    int min;
    struct segTreeNode *left;
    struct segTreeNode *right;
    segTreeNode(int start, int end)
    {
        this->start = start;
        this->end = end;
        left = NULL;
        right = NULL;
    }
};


void display_tree(vector<vector<int>> &vec)
{
    int sze = vec.size()-1;
    for(vector<int> temp: vec){
        ostringstream out;
        int count = sze--;
        int space = 0;
        while(count--)
        {
            space+=pow(2,count);
        }
        space++;
        out << left << setw(space);
        for(int a: temp)
        {
            if(a == INT_MIN) {
                cout << setw(space/2) << -1;
            } else{
                cout << setw(space/2) << a ;
            }
        }
        cout << endl;
    }
}




segTreeNode* build(vector<int> &arr, int start, int end)
{
    if(start>end) return NULL;
    struct segTreeNode *root = new segTreeNode(start, end);
    if(start==end)
    {
        root->min = start;
        return root;
    }
    int mid = (start+end)/2;
    root->left = build(arr, start, mid);
    root->right = build(arr, mid+1, end);
    root->min = (arr[root->left->min]< arr[root->right->min])?root->left->min:root->right->min;
    return root;
}

int query(struct segTreeNode *root, vector<int> &arr, int start, int end)
{
    if(root == NULL || start > root->end || end < root->start) return -1;
    if(start <= root->start && end >= root->end)
        return root->min;
    int leftMin = query(root->left, arr, start, end);
    int rightMin = query(root->right, arr, start, end);
    if (leftMin == -1) return rightMin;
    if (rightMin == -1) return leftMin;
    return arr[leftMin] < arr[rightMin]? leftMin:rightMin;
}

struct segTreeNode *buildSegmentTree(vector<int>& heights, int start, int end) {
    if (start > end) return NULL;
    struct segTreeNode *root = new segTreeNode(start, end);
    if (start == end) {
        root->min = start;
        return root;
    } else {
        int middle = (start + end) / 2;
        root->left = buildSegmentTree(heights, start, middle);
        root->right = buildSegmentTree(heights, middle + 1, end);
        root->min = heights[root->left->min] < heights[root->right->min] ? root->left->min : root->right->min;
        return root;
    }
}

//int query(struct segTreeNode *root, vector<int>& heights, int start, int end) {
//    if (root == NULL || end < root->start || start > root->end) return -1;
//    if (start <= root->start && end >= root->end) {
//        return root->min;
//    }
//    int leftMin = query(root->left, heights, start, end);
//    int rightMin = query(root->right, heights, start, end);
//    if (leftMin == -1) return rightMin;
//    if (rightMin == -1) return leftMin;
//    return heights[leftMin] < heights[rightMin] ? leftMin : rightMin;
//}

bool compare_tree(struct segTreeNode *root1, struct segTreeNode *root2)
{
    if((root1 == NULL) && (root2 == NULL))
        return true;

    if(root1 == NULL || root2 == NULL)
        return false;

    if(root1->min != root2->min)
        return false;
    return compare_tree(root1->left, root2->left) && compare_tree(root1->right, root2->right);
}

vector<vector<int>> print_tree(struct segTreeNode *root, vector<int> &arr)
{
    vector<vector<int>> pt;
    if(root != NULL) {
        queue<struct segTreeNode *> q;
        int n;
        struct segTreeNode *temp;
        q.push(root);

        while (!q.empty()) {
            vector<int> vec;
            n = q.size();
            cout << endl;
            while (n--) {
                temp = q.front();
                q.pop();
                if (temp) {
                    cout << arr[temp->min] << " ";
                    vec.push_back(arr[temp->min]);
                } else {
                    vec.push_back(INT_MIN);
                }
                if (temp) {
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
            pt.push_back(vec);
        }
    }
    return pt;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("segTree_usingTree_ip.txt", "r", stdin);
    freopen("segTree_usingTree_op.txt", "w", stdout);
#endif
    int n, start, end, qry;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    struct segTreeNode *root2 = build(arr, 0, arr.size() - 1);
    cin >> qry;
    while(qry--) {
        cin >> start >> end;
//    struct segTreeNode *root1 = buildSegmentTree(arr, 0, arr.size()-1);
        int min = query(root2, arr, start, end);
        cout << "minimum between " << start << " and " << end << " = " << arr[min] << endl;
    }
}