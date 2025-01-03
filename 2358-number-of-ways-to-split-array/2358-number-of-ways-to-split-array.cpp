class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> insc(nums.size(), 0);
        vector<long long> decs(nums.size(), 0);

        
        insc[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            insc[i] = insc[i - 1] + nums[i];
        }

        
        decs[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            decs[i] = decs[i + 1] + nums[i];
        }

        
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (insc[i] >= decs[i + 1]) {
                res++;
            }
        }

        return res;
    }
};
