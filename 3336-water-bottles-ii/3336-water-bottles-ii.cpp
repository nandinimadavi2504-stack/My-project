class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrank = numBottles;  // initially drink all
        int empty = numBottles;       // now all are empty bottles

        while (empty >= numExchange) {
            // Exchange numExchange empty bottles for 1 full bottle
            empty -= numExchange;   // spend numExchange empty bottles
            numExchange++;          // next exchange cost increases
            totalDrank++;           // drink the new bottle
            empty++;                // that bottle becomes empty
        }

        return totalDrank;
        
    }
};