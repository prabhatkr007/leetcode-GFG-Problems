/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function(root) {
    
    if(root === null){
        return [];
    }
    
    let ans = [];
    
    var traversal = function (node){
        
        if(node === null){
            return [];
        }
        
        traversal(node.left);
        ans.push(node.val);
        traversal(node.right);
    }
    
    traversal(root);
    
    return ans;
    
};