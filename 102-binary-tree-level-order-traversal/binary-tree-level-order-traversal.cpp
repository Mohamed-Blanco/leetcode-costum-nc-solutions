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

    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == nullptr ) return {}; 
        std::vector<vector<int>> levels {}; //storing all the levels 
        queue<TreeNode*> nodes{};
        nodes.push(root); 


        while(!nodes.empty())
        {
            int n = nodes.size(); //getting the current size 
            std::vector<int> level {}; 

            for(int i = 0 ; i < n ; ++i)
            {
                TreeNode* node = nodes.front();
                nodes.pop(); 

                level.push_back(node->val); 

                if(node->left != nullptr )
                {
                    nodes.push(node->left);
                }
                
                if(node->right != nullptr)
                {
                    nodes.push(node->right); 
                }
            }
            
            levels.push_back(level); 
        }
    
        return levels;
    }
};