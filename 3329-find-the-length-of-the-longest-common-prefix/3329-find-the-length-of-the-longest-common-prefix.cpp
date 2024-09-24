class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>st;

        for(int x: arr1)
        {
            while(! st.count(x) && x> 0)
            {
                st.insert(x);
                x = x/10;
            }

        }
        int result  =0 ;
        for(int num : arr2)
        {
            while(!st.count(num) && num >0 )
            {
                num /= 10;
            }

            if(num > 0)
            {
                result = max(result,static_cast<int>(log10(num)+1));
            }
        }


        return result;
    }
};