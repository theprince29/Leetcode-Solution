problem link: https://leetcode.com/problems/find-the-original-array-of-prefix-xor/submissions/1088476969/



class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
            vector<int> v;
            v.push_back(pref[0]);

            for(int t=1;t<pref.size();t++)
            {
                v.push_back(pref[t]^pref[t-1]);
            }
        return v;
    }
};
