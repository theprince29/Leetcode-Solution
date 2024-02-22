class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts(n + 1, 0); // Count of trusts each person receives
        vector<int> trustedBy(n + 1, 0); // Count of people each person trusts

        for (const auto& relation : trust) {
            int a = relation[0];
            int b = relation[1];
            trusts[b]++;
            trustedBy[a]++;
        }

        for (int i = 1; i <= n; i++) {
            if (trusts[i] == n - 1 && trustedBy[i] == 0) {
                return i; // i is the judge
            }
        }
        return -1; // No judge found
    }
};