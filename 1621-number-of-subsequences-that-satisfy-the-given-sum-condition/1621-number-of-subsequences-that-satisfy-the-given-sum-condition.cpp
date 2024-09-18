class Solution {

int MOD  = 1e9+7;
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
    sort(nums.begin(), nums.end());  
    
    vector<int> pow2(n, 1); 
    for (int i = 1; i < n; ++i) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }
    
    int left = 0, right = n - 1;
    int result = 0;

    while (left <= right) {
        if (nums[left] + nums[right] <= target) {
            // All subsequences between left and right are valid
            result = (result + pow2[right - left]) % MOD;
            left++;  // Move left pointer right to consider more subsequences
        } else {
            right--;  // Move right pointer left to reduce the sum
        }
    }
    
    return result;
    }
};