class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> res;

        for (int s : spells) {
            long long minPotion = (success + s - 1) / s; 
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);
            int count = potions.end() - it;
            res.push_back(count);
        }

        return res;
    }
};