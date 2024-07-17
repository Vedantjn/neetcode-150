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
    int preorderIndex = 0;
    
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int inorderStart, int inorderEnd) {
        if (inorderStart > inorderEnd) {
            return nullptr;
        }
        
        int inorderIndex;
        TreeNode* root = new TreeNode(preorder[preorderIndex++]);
        
        for (int i = inorderStart; i <= inorderEnd; ++i) {
            if (inorder[i] == root->val) {
                inorderIndex = i;
                break;
            }
        }
        
        root->left = constructTree(preorder, inorder, inorderStart, inorderIndex - 1);
        root->right = constructTree(preorder, inorder, inorderIndex + 1, inorderEnd);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return constructTree(preorder, inorder, 0, n - 1);
    }
};
