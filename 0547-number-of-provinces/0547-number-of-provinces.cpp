class Solution {
    
    void dfs(int node, vector<bool> &vis,  unordered_map<int, list<int> > adj ){
        vis[node] = true;
        
        for(auto neighbours: adj[node]){
            if(!vis[neighbours])
            dfs(neighbours, vis, adj);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, list<int> > adj;
        int n = isConnected.size();
        
        // creating adj list
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }
        
        int count = 0;
         vector<bool> vis(n,false);
        
        for(int i = 0 ; i < isConnected.size(); i++){
            
            if(!vis[i]){
            count++;
            dfs(i, vis, adj);
                
            }
        }
        
        return count;
    }
};