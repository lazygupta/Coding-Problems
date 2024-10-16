// Simple build a maxheap, check for the string is having last two repetetive or not
// If its repetetive then add second frequenct ele
// And push the updated counting 
// if not reptetive then add directly the top heap ele
// And update the count in  maxHeap eveyrtime u do modification

// T.C = O(N)
// S.C = O(1)


typedef pair<int,char> pic;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string str = "";
        priority_queue<pic> maxH;
        if(a>0) maxH.push({a,'a'});
        if(b>0) maxH.push({b,'b'});
        if(c>0) maxH.push({c,'c'});
        while(!maxH.empty()){
            auto [count1,char1] = maxH.top();
            maxH.pop();
            if(str.size() >=2 && str.back() == char1 && str[str.size()-2] == char1){
                if(maxH.empty()) break;

                auto [count2,char2] = maxH.top();
                maxH.pop();

                str += char2;
                count2--;

                if(count2>0)
                maxH.push({count2,char2});

                maxH.push({count1,char1});
            } else {
                str += char1;
                count1--;
                if(count1>0) maxH.push({count1,char1});
            }
        }
        return str;
    }
};