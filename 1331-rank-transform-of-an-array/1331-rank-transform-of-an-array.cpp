class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
         if (arr.empty()) return {};

        vector<pair<int, int>> temp;
        for (int i = 0; i < arr.size(); i++) {
            temp.push_back({arr[i], i});
        }

        sort(temp.begin(), temp.end());

     
        vector<int> ans(arr.size());

       
        int rank = 1;
        ans[temp[0].second] = rank; 

        for (int i = 1; i < temp.size(); i++) {
            if (temp[i].first != temp[i - 1].first) {
                rank++;
            }
            ans[temp[i].second] = rank;
        }

        return ans;
    }
};