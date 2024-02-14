class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v;
        vector<int> a;
        vector<int> b;
        for(int i=0 ; i<nums.size();i++){
            if(nums[i]<0)
            {
                b.push_back(nums[i]);
            }
            else
            {
                a.push_back(nums[i]);                
            }
        }
        
        if(a.size() == nums.size() || b.size() == nums.size()) return nums;
            
        int pos=0; int neg =0;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2 == 0)
            {
                v.push_back(a[pos]);
                pos++;
            }
            else
            {
                v.push_back(b[neg]);
                neg++;
            }
            
        }
        
        return v;
    }
};