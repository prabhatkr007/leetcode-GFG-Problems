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
    TreeNode* searchBST(TreeNode* root, int val) {
        
    TreeNode* temp1 = NULL;
    TreeNode* temp2 = NULL;
        
    if(root == NULL) return NULL;
        
    if(root -> val == val) return root;
     
    if(val > root-> val){
        temp1 =  searchBST(root-> right, val);
    }   
     else{
       temp2 =  searchBST(root-> left, val);
    }
    
    if(temp1) return temp1;
    else return temp2;
     
    } 
};