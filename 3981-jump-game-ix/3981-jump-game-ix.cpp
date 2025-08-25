class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return {};

        vector<int> Maxprefix(n);
        vector<int> Minsuffix(n);
        vector<int> ans(n);

        Maxprefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            Maxprefix[i] = max(Maxprefix[i - 1], nums[i]);
        }

        Minsuffix[n - 1] = nums[n - 1];
        for (int j = n - 2; j >= 0; j--) {
            Minsuffix[j] = min(Minsuffix[j + 1], nums[j]);
        }

        ans[n - 1] = Maxprefix[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (Maxprefix[i] > Minsuffix[i + 1]) {
                ans[i] = ans[i + 1];
            } else {
                ans[i] = Maxprefix[i];
            }
        }

        return ans;
    }
};