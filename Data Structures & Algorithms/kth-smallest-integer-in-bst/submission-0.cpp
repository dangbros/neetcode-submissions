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
    int cnt = 1;
    int ans;
    void inOrder(TreeNode* node, int k){
        if(node == nullptr) return;

        inOrder(node->left, k);
        if(cnt == k)
            ans = node->val;
        cnt++;
        inOrder(node->right, k);

    }
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return ans;
    }
};
