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

    bool traverse(TreeNode* root,long min , long max)
    {
        if(root != nullptr) 
        {
            if(root->val <= min || root->val >= max) return false; 
            else return traverse(root->left,min,root->val) && traverse(root->right,root->val,max); 
        }

        return true; 
    }

    bool isValidBST(TreeNode* root) {
        
        return traverse(root,LLONG_MIN,LLONG_MAX); 
    }
};