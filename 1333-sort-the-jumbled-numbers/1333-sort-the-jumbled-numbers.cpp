class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
                vector<pair<long long, int>> mappedNums;

        for (int num : nums) {
            int original = num; 
            long long mappedValue = 0;
            long long place = 1;
            if (num == 0) {
                mappedValue = mapping[0];
            } else {
                while (num > 0) {
                    int digit = num % 10;
                    mappedValue += mapping[digit] * place;
                    place *= 10;
                    num /= 10;
                }
            }
            mappedNums.push_back({mappedValue, original});
        }

        
        sort(mappedNums.begin(), mappedNums.end(), [](const pair<long long, int>& a, const pair<long long, int>& b) {
            return a.first < b.first;
        });

        
        vector<int> result;
        for (const auto& p : mappedNums) {
            result.push_back(p.second);
        }

        return result;
    }
};
