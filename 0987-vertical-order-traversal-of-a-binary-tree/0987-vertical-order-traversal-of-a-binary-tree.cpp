class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }

        map<int, vector<int>> columns;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            map<int, vector<int>> level;

            for (int i = 0; i < size; ++i) {
                auto it = q.front();
                TreeNode* node = it.first;
                int hd = it.second;
                q.pop();

                level[hd].push_back(node->val);

                if (node->left) {
                    q.push({node->left, hd - 1});
                }

                if (node->right) {
                    q.push({node->right, hd + 1});
                }
            }

            for (auto& l : level) {
                sort(l.second.begin(), l.second.end());
                
                columns[l.first].insert(columns[l.first].end(), l.second.begin(), l.second.end());
            }
        }

        for (auto& col : columns) {
            ans.push_back(col.second);
        }

        return ans;
    }
};