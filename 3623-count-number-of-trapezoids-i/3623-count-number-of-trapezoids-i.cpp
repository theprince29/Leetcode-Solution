class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long MOD = 1e9+7;
        unordered_map<int, long long> freq; 
        for (auto &p : points) {
            freq[p[1]]++; 
        }

        vector<long long> segments;
        for (auto &it : freq) {
            long long k = it.second;
            if (k >= 2) {
                long long s = (k * (k - 1)) / 2; 
                segments.push_back(s % MOD);
            }
        }

        if (segments.size() < 2) return 0;

        long long total = 0;
        long long sqSum = 0;

        for (long long s : segments) {
            total = (total + s) % MOD;
            sqSum = (sqSum + (s * s) % MOD) % MOD;
        }


        long long ans = (total * total) % MOD;
        ans = (ans - sqSum + MOD) % MOD;

        
        long long inv2 = (MOD + 1) / 2;
        ans = (ans * inv2) % MOD;

        return ans;
    }
};