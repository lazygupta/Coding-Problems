// This is a very important question involving greedy

// First we have to remove the element from start to end in monotnoic increasing way
// We should try to choose and remove the element which is greater than next

// So this is basically NGE

// Now , first of all make a stack arramged in monotonic increasing way while keeping the k value k>=0
// Also we should not consider zero to be entered into the stack
// After doing such operation remove the element from back side

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(k >= num.length()) return "0";
        string ans = "";
        for(int i=0;i<n;i++){
            while(ans.length() && ans.back() > num[i] && k){
                ans.pop_back();
                k--;
            }
            if(ans.length() || num[i]!='0') ans.push_back(num[i]);
        }
        while(ans.size() && k--){
            ans.pop_back();
        }
        return ans==""?"0":ans;
    }
};

