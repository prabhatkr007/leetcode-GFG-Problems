/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void mark(TreeNode* root, unordered_map <TreeNode*, TreeNode*> &parentMap ){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();
                
                if(node -> left){
                    q.push(node -> left);
                    parentMap[node -> left] = node;
                }
                
                if(node -> right){
                    q.push(node -> right);
                    parentMap[node -> right] = node;
                }
                
            }
        }
        
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map <TreeNode*, TreeNode*> parentMap;
        
        mark(root, parentMap);
        
        unordered_map < TreeNode* , bool> visited;
        queue<TreeNode*> q;
        
        q.push(target);
        visited[target] = true;
        
        int level = 0;
        
        while(!q.empty()){
            int size = q.size();
            
            if(level == k) break;
            level++;
            
            for(int i = 0; i < size; i++){
                
                TreeNode* node = q.front();
                q.pop();
                
                if(node -> left && !visited[node -> left]) {
                    q.push(node -> left);
                    visited[node -> left] = true;
                }
                
                 if(node -> right  && !visited[node -> right]) {
                    q.push(node -> right);
                    visited[node -> right] = true;
                }
                
                 if(parentMap[node] && !visited[parentMap[node]]) {
                    q.push(parentMap[node]);
                    visited[parentMap[node]] = true;
                }
            }
            
        }
        
        vector <int> ans;
        
        while(!q.empty()){
            ans.push_back(q.front() -> val);
            q.pop();
        }
        
        return ans;
        
    }
};