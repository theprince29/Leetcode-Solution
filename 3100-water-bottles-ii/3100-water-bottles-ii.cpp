class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
    int total_bot = numBottles;
        int eb = numBottles;
        while(eb>=numExchange)
        {
            eb = (eb-numExchange)+1;
            numExchange++;
            total_bot++;
        }
        return total_bot;
    }
};