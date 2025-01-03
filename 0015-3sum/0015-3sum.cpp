class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     vector<vector<int>> result;

    // Sort the array to use the two-pointer approach
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
        // Skip duplicate elements for `i`
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1, right = nums.size() - 1;

        while (left < right) {
            int total = nums[i] + nums[left] + nums[right];

            if (total == 0) {
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicates for `left` and `right`
                while (left < right && nums[left] == nums[left + 1]) ++left;
                while (left < right && nums[right] == nums[right - 1]) --right;

                ++left;
                --right;
            } else if (total < 0) {
                ++left;  // Increase the sum
            } else {
                --right;  // Decrease the sum
            }
        }
    }

    return result;
}
};