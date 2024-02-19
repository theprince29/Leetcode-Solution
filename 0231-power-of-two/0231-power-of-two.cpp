class Solution {
public:
    bool isPowerOfTwo(int n) {
        int s =  __builtin_popcount(n);
        return n>0 && s==1;    
    }
};