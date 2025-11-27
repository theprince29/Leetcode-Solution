class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<long long> best(k, LLONG_MAX);
        long long ans = LLONG_MIN;
        for (int i = 0; i <= n; i++) {
            int rem = i % k;

            if (best[rem] != LLONG_MAX) {
                long long sum = prefix[i] - best[rem];
                ans = max(ans, sum);
            }

            best[rem] = min(best[rem], prefix[i]);
        }

        return ans;
    }
};