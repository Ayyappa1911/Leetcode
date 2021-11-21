#include<bits/stdc++.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        TreeNode *q = NULL;
        if(inorder.size() !=0)
        {
            return Recursive(inorder,postorder);
        }
        return q;   
    }
    TreeNode* newnode(int a)
    {
        // TreeNode* temp = (struct TreeNode*)malloc(sizeof(TreeNode));
        TreeNode* temp = new TreeNode;
        temp -> val = a;
        temp -> left = NULL;
        temp -> right = NULL;
        return temp;
    }
    TreeNode* Recursive(vector<int>& inorder,vector<int>& postorder)
    {
        TreeNode* q = NULL; 
        if(inorder.size()!=0 || postorder.size()!=0)
        {
            // TreeNode *node;
            TreeNode *node = newnode(postorder[postorder.size() - 1]);
            int i = 0;
            for(auto it : inorder)
            {
                if(it == postorder[postorder.size() - 1])
                {
                    break;
                }
                i++;
            }
            // cout << i << endl;
            vector<int> a1;
            vector<int> b1;
            vector<int> a2;
            vector<int> b2;
            for(int j = 0;j<i;j++)
            {
                a1.push_back(inorder[j]);
                b1.push_back(postorder[j]);
            }
            for(int j = i+1;j<postorder.size();j++)
            {
                a2.push_back(inorder[j]);
                b2.push_back(postorder[j-1]);
            }
            cout << a2.size() << "y" << endl;
            node -> left = Recursive(a1,b1);
            node -> right =  Recursive(a2,b2);
            return node;
        }
        return q;
    }
};