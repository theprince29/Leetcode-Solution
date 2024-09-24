class Solution {

private:
int MOD  = 1e9+7;
    int fun(int ind, int target, vector<int>& nums,vector<vector<int>>&dp) {
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        
        if(ind == 0) {
            if(target == 0 && nums[ind] == 0) return 2; 
            if(target == 0 || target == nums[0]) return 1;
            return 0;
        }
        
        int nottake = fun(ind - 1, target, nums,dp);
        int take = 0;
        if(nums[ind] <= target) take = fun(ind - 1, target - nums[ind], nums,dp);
        
        return dp[ind][target] = (nottake + take)%MOD;
    }


public:
    int findTargetSumWays(vector<int>& nums, int d) {
        int ts = 0;
        for(int i : nums) ts += i;
        
        int n = nums.size();
        
        if(ts - d < 0 || (ts - d) % 2 != 0) return 0;
        
        int target = (ts - d) / 2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return fun(n - 1, target, nums,dp);
    }
};