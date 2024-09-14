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
     void findPaths(TreeNode* root, string path, vector<string>& paths) {
        if (!root) return;
         
        path += to_string(root->val);

        if (!root->left && !root->right) {
            paths.push_back(path);
        } else {
            path += "->";
            if (root->left) findPaths(root->left, path, paths);
            if (root->right) findPaths(root->right, path, paths);
        }
        
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        findPaths(root, "", paths);
        return paths;
    }
};