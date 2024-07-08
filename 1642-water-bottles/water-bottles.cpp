class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalBottles =0; int emptyBottles=0;
        while(numBottles>0){
            totalBottles += numBottles;
            emptyBottles += numBottles;
            numBottles = emptyBottles/numExchange;   //exchange empty bottles with new bottles
            emptyBottles = emptyBottles%numExchange; // calculate remaining empty bottles
        }
        return totalBottles;
    }
        
};