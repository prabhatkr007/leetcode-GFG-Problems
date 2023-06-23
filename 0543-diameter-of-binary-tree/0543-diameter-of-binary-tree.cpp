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
    int height(TreeNode* root){
        
        if(root == NULL) return 0;
        
        return max(height(root -> left), height(root -> right)) +1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        
        int opt1 = diameterOfBinaryTree(root -> left);
        int opt2 = diameterOfBinaryTree(root -> right);
        
        int op3 = height(root -> left) + height(root -> right) ;
        
        
        return max(op3, max(opt1,opt2));
    }
};