class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        getLeafSequence(root1, leaves1);
        getLeafSequence(root2, leaves2);

        return leaves1 == leaves2;
    }

    void getLeafSequence(TreeNode* root, vector<int>& leaves) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            leaves.push_back(root->val);
        }

        getLeafSequence(root->left, leaves);
        getLeafSequence(root->right, leaves);
    }
};