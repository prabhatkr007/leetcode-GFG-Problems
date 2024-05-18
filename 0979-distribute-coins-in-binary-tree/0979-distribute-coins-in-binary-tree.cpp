class Solution {
    int countSteps(TreeNode* root, int &moves) {
        if (root == nullptr) return 0;
        
        int leftCoins = countSteps(root->left, moves);
        int rightCoins = countSteps(root->right, moves);
        
        moves += abs(leftCoins) + abs(rightCoins);
        return (root->val - 1) + leftCoins + rightCoins;
    }
public:
   
    
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        countSteps(root, moves);
        
       return moves;
    }
    
    
};