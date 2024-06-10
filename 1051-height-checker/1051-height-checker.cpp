class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>v = heights;
        int count=0;
        sort(v.begin(),v.end());
        for(int i=0;i<heights.size();i++)
        {
            if(v[i]!=heights[i])
                count++;
        }
        return count;
        
    }
};