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
     TreeNode* buildBST(vector<int>& preorder, int& index, int lower, int upper) {
        if (index == preorder.size()) return nullptr;
        
        int val = preorder[index];
         
        if (val < lower || val > upper) return nullptr;

        
        TreeNode* root = new TreeNode(val);
        index++;
        root->left = buildBST(preorder, index, lower, val);
        root->right = buildBST(preorder, index, val, upper);
        
        return root;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return buildBST(preorder, index, INT_MIN, INT_MAX);
    }

   
};