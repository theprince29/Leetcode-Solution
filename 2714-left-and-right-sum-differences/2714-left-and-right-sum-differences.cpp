class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        vector<int> result;

        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum - nums[i];
            result.push_back(abs(leftSum - rightSum));
            leftSum += nums[i];
        }

        return result;
    }
};