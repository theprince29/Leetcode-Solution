class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       vector<int> s = arr;
        
        
        sort(s.begin(), s.end());
        
        
        unordered_map<int, int> rank;
        int currentRank = 1;
        for (int num : s) {
            if (rank.find(num) == rank.end()) {  
                rank[num] = currentRank;
                currentRank++;
            }
        }

        vector<int> ans(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            ans[i] = rank[arr[i]];
        }
        
        return ans;
    }
};