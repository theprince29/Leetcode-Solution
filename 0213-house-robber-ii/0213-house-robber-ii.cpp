class Solution {
public:
    int rob1(vector<int>& nums) {
         int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev1 = nums[0];
        int prev2 = std::max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i) {
            int current = std::max(prev2, nums[i] + prev1);
            prev1 = prev2;
            prev2 = current;
        }

        return prev2;
    }
    int rob(vector<int>& nums) {
    vector<int>arr1;
    vector<int>arr2;
     
    int n  = nums.size(); 

   

    if(n==1) return nums[0];
    
    for(int i=0; i<n; i++){
        
        if(i!=0) arr1.push_back(nums[i]);
        if(i!=n-1) arr2.push_back(nums[i]);


    }

     return max(rob1(arr1),rob1(arr2));

    }


};