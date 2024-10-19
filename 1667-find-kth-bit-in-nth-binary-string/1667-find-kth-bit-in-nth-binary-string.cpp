class Solution {
public:
    char findKthBit(int n, unsigned k) {
        return k==1?'0':(k==bit_ceil(k)?'1':'0'+1-(findKthBit(n, bit_ceil(k)-k)-'0'));
    }
};