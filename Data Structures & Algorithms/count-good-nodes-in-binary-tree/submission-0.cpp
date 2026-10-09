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
    int count = 0;
    void dfs(TreeNode* node, int maxAnc) {
        if(node == nullptr){
            return;
        }

        if(node->val >= maxAnc)
            count++;
        
        maxAnc = max(maxAnc, node->val);

        dfs(node->left, maxAnc);
        dfs(node->right, maxAnc);
        return;
    }

    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return count;
    }
};
