class Solution {
public:
    bool check(unordered_map<char, int> &mp) {
        for (auto it : mp) {
            if (it.second >= 2) return true;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0;
        for (int right = 0, left = 0; right < s.size(); ++right) {
            mp[s[right]]++;
            for (; check(mp); ++left) {
                if (--mp[s[left]] == 0) {
                    mp.erase(s[left]);
                }
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};