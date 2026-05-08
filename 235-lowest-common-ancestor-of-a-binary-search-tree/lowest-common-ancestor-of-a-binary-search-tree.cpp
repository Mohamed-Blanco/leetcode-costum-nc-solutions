/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void search(TreeNode* root, TreeNode* p, std::vector<TreeNode*>& Outstack) {
        if (root == nullptr)
            return;
        Outstack.push_back(root);
        if (p->val > root->val) {
            search(root->right, p, Outstack);
        } else if(p->val < root->val){
            search(root->left, p, Outstack);
        }else
        {
            return; 
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        std::vector<TreeNode*> stack1{};
        std::vector<TreeNode*> stack2{};

        search(root, p, stack1);
        search(root, q, stack2);

        while (!stack1.empty() || !stack2.empty()) {

            if (stack1.back()->val == stack2.back()->val)
                return stack1.back();

            if (std::size(stack1) >= std::size(stack2))
                stack1.pop_back();
            else
                stack2.pop_back();
        }

        return nullptr;
    }
};