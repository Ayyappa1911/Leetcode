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
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        inorder(root);
        int flag = 0;
        output(root,targetSum,&flag);
        if(flag == 1)
        {
            return true;
        }
        return false;
    }
    void inorder(TreeNode* root)
    {
        if(root)
        {
            if(root->left)
            {
                root -> left -> val = root -> val + root -> left -> val;
            }
            inorder(root->left);
            if(root-> right)
            {
                root -> right -> val = root -> val + root -> right -> val;
            }
            inorder(root->right);
        }
    }
    void output(TreeNode* root,int targetsum,int *flag)
    {
        if(root)
        {
            output(root -> left,targetsum,flag);
            if(root -> left == NULL && root -> right == NULL)
            {
                if(root -> val == targetsum)
                {
                    *flag = 1;
                }
            }
            output(root -> right,targetsum,flag);
        }
    }
};
