class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }



        vector<int> ans;
        ans.reserve(queries.size());

        for(int q : queries) {
            int idx = upper_bound(prefix.begin(), prefix.end(), q) - prefix.begin();
            ans.push_back(idx);
        }
        return ans;
    }
};