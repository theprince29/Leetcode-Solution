class Solution {
public:
     int f(int ind, const std::vector<int>& nums, std::vector<int>& dp) {
        
        if (ind == 0) return nums[ind];
        if (ind < 0) return 0;

        
        if (dp[ind] != -1) return dp[ind];

        int take = nums[ind] + f(ind - 2, nums, dp);
        int notTake = f(ind - 1, nums, dp);

        dp[ind] = std::max(take, notTake);
        return dp[ind];
    }

    int rob(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n, -1); // Initialize dp array with -1
        return f(n - 1, nums, dp);  // Start from the last house
    }
};