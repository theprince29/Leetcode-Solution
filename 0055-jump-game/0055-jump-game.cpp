class Solution {
public:
    int dp[10005];
    bool solve(int idx, vector<int> &nums) {
        if (idx >= nums.size() - 1) return true;
        if (nums[idx] == 0) return false;
        if (~dp[idx]) return dp[idx];
        bool ans = false;
        for (int j = idx + 1; j <= idx + nums[idx]; ++j) {
            ans |= solve(j, nums);
            if (ans == true) return true;
        }
        return dp[idx] = ans;
    }
    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums);
    }
};