class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        int totalsum = accumulate(nums.begin(), nums.end(), 0LL) % p;

        if (totalsum == 0)
            return 0;

        unordered_map<int, int> prefixmap;
        prefixmap[0] = -1;
        int prefixsum = 0;
        int minlen = nums.size();

        for (int i = 0; i < nums.size(); ++i) {

            prefixsum = (prefixsum + nums[i]) % p;

            int target = (prefixsum - totalsum + p) % p;

            if (prefixmap.find(target) != prefixmap.end()) {
                minlen = min(minlen, i - prefixmap[target]);
            }

            prefixmap[prefixsum] = i;
        }

        return minlen == nums.size() ? -1 : minlen;
    }
};