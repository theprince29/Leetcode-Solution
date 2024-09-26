class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int d) {
    int ts = 0;
    for(int i : nums) ts += i;  
    
    int n = nums.size();
    
    
    if(ts - d < 0 || (ts - d) % 2 != 0) return 0;
    
    int target = (ts - d) / 2; 
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    vector<int>prev(target+1,0);
    vector<int>curr(target+1,0);
    
    for(int t = 0; t <= target; t++) {
        if(t == 0 && nums[0] == 0) prev[t] = 2;
        else if(t == 0 || t == nums[0]) prev[t] = 1;  
        else prev[t] = 0;
    }

    
    for(int i = 1; i < n; i++) {
        for(int tar = 0; tar <= target; tar++) {
            int notTake = prev[tar];  
            int take = 0;
            if(nums[i] <= tar) take = prev[tar - nums[i]];  
            curr[tar] = notTake + take;
        }
        prev = curr;
    }

    return prev[target];
}

};