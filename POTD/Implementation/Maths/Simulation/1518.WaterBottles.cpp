// Simple intuition 
// Implementation problem

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
        int drinkBottles = 1;
        while(drinkBottles){
            drinkBottles = numBottles/numExchange;
            total += drinkBottles;
            int remain = drinkBottles + numBottles%numExchange;
            numBottles = remain;
        }
        return total;
    }
};