class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainder_count;

        
        for (int num : arr) {
            int remainder = ((num % k) + k) % k;
            remainder_count[remainder]++;
        }

        
        for (int i = 0; i < k; i++) {
            if (i == 0) {
        
                if (remainder_count[i] % 2 != 0) {
                    return false;
                }
            } else {
        
                if (remainder_count[i] != remainder_count[k - i]) {
                    return false;
                }
            }
        }

        return true;
    }
};