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
    
    int binaryToInt(vector<int>& temp) {
        int value = 0;
        for (int bit : temp) {
            value = value * 2 + bit;
        }
        return value;
    }
    
    void solve(TreeNode* root, vector<int>& temp, int& sum) {
        
        if (root == nullptr) {
            return;
        }

        temp.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            int value = binaryToInt(temp);
            sum += value;
        }

        solve(root->left, temp, sum);
        solve(root->right, temp, sum);

        temp.pop_back();  
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        vector<int> temp;
        int sum = 0;
        solve(root, temp, sum);
        return sum;
    }
};
