class Solution {
public:
   
   bool areSameTree(TreeNode* p, TreeNode* q){
       if(!p || !q){
           return p==NULL && q==NULL;
       } 
       else if(p->val == q->val){    
           return areSameTree(p->left,q->left) && areSameTree(p->right,q->right);
       }
       else{
           return false;
       }
   }
   bool isSubtree(TreeNode* root, TreeNode* subRoot) {
         if(!root){
             return false;
         }   
         else if(areSameTree(root,subRoot)){
             return true;
         }
         else{
             return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
         }
   }
};