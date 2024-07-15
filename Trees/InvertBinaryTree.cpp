class Solution {
public:
    void dfs(TreeNode* root, map<TreeNode*, bool>& visited) {
        if (root == NULL) { 
            return;
        }
        if (visited[root]) { 
            return;
        }
        visited[root] = true;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        dfs(root->left, visited);
        dfs(root->right, visited);
    }

    TreeNode* invertTree(TreeNode* root) {
        map<TreeNode*, bool> visited;
        dfs(root, visited); 
        return root;
    }
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;        
    }
};