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
    void inorder(TreeNode* root, vector<int> &value){
        
        if(root == NULL){
            return ;
        }
        inorder(root -> left,value);
        value.push_back(root -> val);
        inorder(root -> right,value);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> value;
        
        inorder(root, value);
        
        if(value.size() == 1){
            return false;
        }
        
        int low = 0;
        int high =  value.size()-1;
        
        while(low <high){
            int temp = value[high] + value[low];
            if(temp == k){
                return true;
            }
            
            if(temp > k){
                high--;
            }
            
            if(temp < k){
                low++;
            }
        }
        return false;
        
    }
};