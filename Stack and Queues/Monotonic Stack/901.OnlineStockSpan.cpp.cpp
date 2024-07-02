// Intuition
// The question is so good but the way it is given to be implemented confuses all. If it would have been given the arrays of prices then we can simply find the Previous Larger Element of every price and then find the distance of each element from its PLE.

// Approach
// For this question we are storing the span of the prices everytime the next price is greater than the current price.
// How we are doing this?
// Suppose 100 80 60 70 60 75 85
// Index -_____0__1__2__3__4__5__6
// By default every price has span of 1 day.
// So,

// For 100 the span will be 1 as there is no smaller element b4 that
// Stack has now {100,1}
// For 80 the span will be 1 , same reason
// Stack has now {80,1} {100,1}
// For 60 the span will be 1,
// Stack has now {60,1} {80,1} {100,1}
// Now comes the 70 (b4 which the element is smaller), the span will be 1 + top of stack ( last element to be smaller) i.e., 1 + 1 = 2, And we will pop out 60 from stack, as we got that the previous greater element is at dist 2 from 70.
// Stack has now {70,2} {80,1} {100,1}
// 60 -> Span will be 1, as there is no smaller element b4 that
// Stack has now {60,1} {70,2} {80,1} {100,1}
// 75 -> As again previous element is smaller so span will be 1 + top of stack i.e., 1+1 = 2 ------Pop 60 and,
// Again the stack top element 70 is smaller that 75 so span will be 2 + top of stack i.e., 2+2 = 4... Pop 70 too.... Now as we already calculated that 70 is at dist 2 from largest so it is counted.
// Lets say that before 70 there would be 75 then the above calculation for 75(5th index) (Span = 2+2 = 4) would be wrong but that is not so, because if that would be the case then 70 would be holding span 1 because 75 is just beside of it. So the span would be 2+1 = 3
// Stack has now {75,4}, {80,1} , {100,1}
// 85 -> Span will be 4(of 75) + 1(of 80) + 1(of 100) i.e., 6

class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int dist = 1;
        while(!st.empty() && st.top().first <= price){
            dist += st.top().second;
            st.pop();
        }
        st.push({price,dist});
        return dist;
    }
};
