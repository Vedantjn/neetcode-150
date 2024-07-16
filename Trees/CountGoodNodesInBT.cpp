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
    void goodCount(TreeNode* root, int max, int& ans){
        if (root == NULL) return; 
        if (root->val >= max){
            ans ++;
            max = root->val;
        }
        goodCount(root->left, max, ans);
        goodCount(root->right, max, ans);

    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        int max = root->val;
        goodCount(root,max,ans);
        return ans;
    }
};