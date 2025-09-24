class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {{'I', 1},   {'V', 5},   {'X', 10},
                                          {'L', 50},  {'C', 100}, {'D', 500},
                                          {'M', 1000}};

        int sum = 0;
        int prev = 0;
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            char x = *it;
            if (prev > roman[x]) {
                sum -= roman[x];
            } else {
                prev = roman[x];
                sum += roman[x];
            }
        }
        return sum;
    }
};