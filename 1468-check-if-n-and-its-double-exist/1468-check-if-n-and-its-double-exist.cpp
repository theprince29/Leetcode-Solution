class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int>st(arr.begin(),arr.end());
        for(int i =0 ; i<arr.size();i++)
        {
            if(st.count(2*arr[i]))
            {
                auto it = find(arr.begin(), arr.end(), 2*arr[i]);
                if(distance(arr.begin(), it) == i ) continue;
                return true;
            }

        }
        return false;
    }
};