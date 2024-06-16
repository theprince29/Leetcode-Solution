class Solution {
public:


    bool canMeasureWater(int x, int y, int target) {
        if(x+y>=target){ 
        if(target% gcd(x,y)==0)
        return true;
        }
        return false;
    }
};