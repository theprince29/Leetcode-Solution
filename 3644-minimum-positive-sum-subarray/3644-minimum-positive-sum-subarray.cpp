class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int ans = INT_MAX;
        bool found = false;

        for (int len = l; len <= r; len++) {
            for (int start = 0; start + len <= n; start++) {
                int end = start + len - 1;
                int sub_sum = prefix[end + 1] - prefix[start];
                if (sub_sum > 0) {
                    ans = min(ans, sub_sum);
                    found = true;
                }
            }
        }

        return found ? ans : -1;
    }
};