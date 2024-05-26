class Solution {
    int dfs(TreeNode* node, long long currentSum, int targetSum, unordered_map<long long, int>& prefixSumCount) {
        if (!node) return 0;

        currentSum += node->val;
        int numPaths = prefixSumCount[currentSum - targetSum];

        prefixSumCount[currentSum]++;
        numPaths += dfs(node->left, currentSum, targetSum, prefixSumCount);
        numPaths += dfs(node->right, currentSum, targetSum, prefixSumCount);
        prefixSumCount[currentSum]--;

        return numPaths;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1; 
        return dfs(root, 0, targetSum, prefixSumCount);
    }

    
};