class Solution {
public:
    vector<int> smallest_factor;
    void sieve(int maximum) {
        smallest_factor.assign(maximum + 1, 0);
        for (int p = 2; p <= maximum; ++p) {
            if (smallest_factor[p] == 0) {
                smallest_factor[p] = p;  
                for (int i = p * 2; i <= maximum; i += p) {
                    if (smallest_factor[i] == 0) {
                        smallest_factor[i] = p; 
                    }
                }
            }
        }
    }

 int minOperations(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        sieve(maxi + 1);
        int n = nums.size();
        int last = nums.back();
        int ans = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] > last) {
                nums[i] = smallest_factor[nums[i]];
                ans++;
            }
            if (nums[i] > last) return -1;
            last = nums[i];
        }
        return ans;
    }

};