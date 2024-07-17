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
    void inorder(TreeNode* root, int& k, int& ans) {
        if (!root) return;
        
        // Traverse left subtree
        inorder(root->left, k, ans);

        // Process current node
        if (--k == 0) {
            ans = root->val;
            return;
        }
        
        // Traverse right subtree
        inorder(root->right, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = -1; // Initialize ans with an invalid value
        inorder(root, k, ans);
        return ans;
    }
};
