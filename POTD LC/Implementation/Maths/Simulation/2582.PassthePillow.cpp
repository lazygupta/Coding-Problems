//First we check in that time how many pillow has passed and stored as current
// Then we store how many time are left for the pillow to be passed

// If the current position of pillow is left before finishing the last pillow, Then the n-remain will be the positon
// Or else pillow has changed the direction because it has not surpassed the finishing pillow, So 1 + remain;

class Solution {
public:
    int passThePillow(int n, int time) {
        int curr = time/(n-1);
        int remain = time%(n-1);
        if(curr%2){
            return n-remain;
        }
        else return 1+remain;
    }
};