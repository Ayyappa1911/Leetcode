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
    int sumNumbers(TreeNode* root)
    {
        inorder(root);
        int sum = 0;
        inorder1(root,&sum);
        return sum;
    }
    void inorder(TreeNode* root)
    {
        if(root)
        {
            if(root -> left)
            {
                (root -> left) -> val = (root -> val) * 10+(root -> left) -> val;
            }
            inorder(root -> left);
            if(root -> right)
            {
                (root -> right) -> val = (root -> val) * 10+(root -> right) -> val;
            }
            inorder(root-> right);
        }
    }
    void inorder1(TreeNode* root,int *sum)
    {
        if(root)
        {
            inorder1(root -> left,sum);
            if(root -> left == NULL && root -> right == NULL)
            {
                *sum = *sum + (root -> val);
                cout << root -> val << endl;
            }
            inorder1(root -> right,sum);
        }
    }
};
