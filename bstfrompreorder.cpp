//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

//Wanna run, see the code below the class

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
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        TreeNode* root = makenode(preorder[0]);
        for(int i = 1;i<preorder.size();i++)
        {
            root = ADD(root,preorder[i]);
        }
        return root;
    }
    TreeNode* ADD(TreeNode* root,int a)
    {
        TreeNode* temp = root;
        while(temp -> val > a)
        {
            if(temp -> left == NULL)
            {
                temp -> left = makenode(a);
                return root;
            }
            else
            {
                temp = temp -> left; 
            }
        }
        while(temp -> val < a)
        {
            if(temp -> right == NULL)
            {
                temp -> right = makenode(a);
                return root;
            }
            else
            {
                temp = temp -> right; 
            }
        }
        return root;
    }
    
    TreeNode* makenode(int v)
    {
        TreeNode* temp = new TreeNode;
        temp -> val = v;
        temp -> left = NULL;
        temp -> right  = NULL;
        return temp;
    }
};





// Code for which output is printed in Inorder traversal

#include<bits/stdc++.h>
using namespace std;


/**
 * Definition for a binary tree node.*/
 struct TreeNode
 {
 	int val;
 	TreeNode *left;
 	TreeNode *right;
 //*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 //*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 //*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        TreeNode* root = makenode(preorder[0]);
        for(int i = 1;i<preorder.size();i++)
        {
            root = ADD(root,preorder[i]);
        }
        return root;
    }
    TreeNode* ADD(TreeNode* root,int a)
    {
        TreeNode* temp = root;
       // cout << "a1 " << a << endl; 
        if(temp -> val > a)
        {
            if(temp -> left == NULL)
            {
                temp -> left = makenode(a);
              //  cout << "a2 " << a << endl; 
                return root;
            }
            else
            {
                temp = temp -> left;
                ADD(temp,a); 
            }
        }
        if(temp -> val < a)
        {
           // cout << "a3 " << a << endl; 
            if(temp -> right == NULL)
            {
                temp -> right = makenode(a);
             //   cout << "a3 " << a << endl; 
                return root;
            }
            else
            {
            	//cout << temp -> val << endl;
                temp = temp -> right; 
                ADD(temp,a);
                //cout << temp -> val << endl;
            }
        }
        return root;
    }
    
    TreeNode* makenode(int v)
    {
        TreeNode* temp = new TreeNode;
        temp -> val = v;
        temp -> left = NULL;
        temp -> right  = NULL;
        return temp;
    }
};
void Inorder(TreeNode* root)
{
	if(root == NULL)
	{
		return;
	}
	Inorder(root->left);
	cout << root->val << " ";
	Inorder(root->right);
	return;
}
int main()
{
	int n;
	cin >> n;
	vector<int> Arr;
	for(int i = 0;i<n;i++)
	{
		int a;
		cin >> a;
		Arr.push_back(a);
	}
	Solution *s;
	TreeNode *root = s->bstFromPreorder(Arr);
	Inorder(root);
	return 0;
}
