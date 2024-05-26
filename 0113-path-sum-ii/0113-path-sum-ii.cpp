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
     void hasPathSum(TreeNode* root, int targetSum, vector<int> &current, vector<vector<int> >&ans) {
        if (!root) return; 

         
        current.push_back(root -> val);
         
        if (!root->left && !root->right && root->val == targetSum) {
            ans.push_back(current);
        }
         
        hasPathSum(root->left, targetSum - root->val, current, ans) ;
        hasPathSum(root->right, targetSum - root->val, current , ans);
        current.pop_back();
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> current;
        vector<vector<int> >ans;
        hasPathSum(root, targetSum, current, ans);
        return ans;
             
    }
};