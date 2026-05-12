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
    std::vector<int> path{}; 
    std::vector<int> DFS(TreeNode* root)
    {
        if(root == nullptr)
        {
            return path; 
        }

        if(root->left != nullptr)
        {
            DFS(root->left); 
        }

        path.push_back(root->val); 

        if(root->right != nullptr)
        {
            DFS(root->right); 
        }

        return path; 
    }

    int kthSmallest(TreeNode* root, int k) {
        
        DFS(root);
        return path.at(k-1); 
    }
};