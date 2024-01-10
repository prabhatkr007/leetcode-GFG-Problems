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
    bool evaluateTree(TreeNode* root) {
        

        if(!root -> left && !root ->right) return root -> val == 1;;
        
        bool temp1 = evaluateTree(root -> left);
        bool temp2 = evaluateTree(root -> right);
        
    
        if(root -> val == 2 ) {
            if(temp1==0 && temp2 == 0) return false ;
            else return true;
        }
            
        if(root -> val == 3){
            if(temp1==1 && temp2 == 1) return true ;
            else return false;
        }
        return true;
    }
    
};