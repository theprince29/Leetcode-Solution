// Problem link : https://leetcode.com/problems/power-of-four/description/
// Date : 23-10-2023
// 342. Power of Four

// level : Easy


// Given an integer n, return true if it is a power of four. Otherwise, return false.

// An integer n is a power of four, if there exists an integer x such that n == 4x.

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;  // 0 and negative numbers are not powers of four
        }

        // Check if n is a power of two
        if ((n & (n - 1)) != 0) {
            return false;
        }

        // Check if the logarithm of n base 4 is an integer
        double log4n = log2(n) / log2(4);
        return floor(log4n) == log4n;
    }
};
