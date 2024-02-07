class Solution {
public:
    
    bool isfunc(int num)
    {
        string numStr = to_string(num);
        if(numStr.size()%2 ==1) return false;
           int n = numStr.size() / 2;
        int sum_first_half = 0;
        int sum_second_half = 0;

        for (int i = 0; i < n; ++i) {
            sum_first_half += numStr[i] - '0'; 
            sum_second_half += numStr[numStr.size() - i - 1] - '0'; 
        }

    return sum_first_half == sum_second_half;
}
    
    
    int countSymmetricIntegers(int low, int high) {
        int count =0;
       while(low<=high)
        {
            if(isfunc(low) && !(0<low && low<=9))
            {
                
                count++;
            }
                
            low++;
        }
        return count;
    }
};