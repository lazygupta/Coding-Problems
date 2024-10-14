class Solution {
public:
    int minSwaps(string s) {
        int i =0;
        int count = 0;
        stack<char> st;
        while(i<s.length()){
            if(s[i] == '['){
                st.push(s[i]);
            } else {
                if(!st.empty()) st.pop();
            } 
            i++;
        }
        // Finally we are left with the half portion of umatched pattern
        // And one swap can solve two unmatched patterns
        // So,
        return (st.size()+1)/2;
    }
};

// Without stack

class Solution {
public:
    int minSwaps(string s) {
        int size = 0;
        for(char &it : s) {
            if(it == '[') size++;
            else if(size > 0) size--;
        }
        return (size+1)/2;
    }
};