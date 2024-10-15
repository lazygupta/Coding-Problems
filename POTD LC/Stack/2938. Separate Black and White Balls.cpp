class Solution {
public:
    long long minimumSteps(string s) {
        int count =0;
        long long res = 0;
        for(auto it:s){
            if(it == '1'){
                count++;
            } else {
                res += count;
            }
        }
        return res;
    }
};