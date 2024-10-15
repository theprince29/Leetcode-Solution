class Solution {
public:
    long long minimumSteps(string s) {
    long long countZeros = 0;
    long long swaps = 0;

    // Traverse the string
    for (char c : s) {
        if (c == '1') {
            countZeros++;  
        } else{ 
            swaps += countZeros;
        }
    }

    return swaps;
    }
};