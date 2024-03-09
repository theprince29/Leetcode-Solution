class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
     
        int i =0 ;
        int j=0;
        int min_common =INT_MAX;
        while(i<nums1.size() && j<nums2.size())
        {
            if (nums1[i] == nums2[j]) {
                min_common = std::min(min_common, nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        if(min_common == INT_MAX) return -1;
        
        
        return min_common;
        
    }
};