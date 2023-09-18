// The problem is given with two strings
// We have to find the no. of anagram of 2nd string in the 1st

//I am proceeding with the optimal solution using sliding window algorithm
// O(n) solution

// Ghabrana nahi hai ye question dekh kr bs sliding windows yaad rkhna hai

// Just decrease the mapping of the alphabet as soon we check for that particular alphabet
// After decrease the mapping check that alphabet value became 0 or not
// If yes then decrease the count value
// Else do nothing
#include<bits/stdc++.h>
using namespace std;

class Anagram{
    public:
    
    int Occurence_of_Anagaram(string text,string pattern){
        //We will store the occurence of alphabets in pattern using map

        unordered_map<char,int> mpp;
        for(int i=0;i<pattern.length();i++){
            mpp[pattern[i]]++;
        }
        int k=pattern.length(); // The size of pattern i.e., The window size

        int i=0,j=0;
        int count=mpp.size();// Storing the no. of different alphabets in count as we will decrease it value whenever the map of alphabet become 0.
        int res=0;

        while(j<text.length()){
            if(mpp.find(text[j])!=mpp.end()){
                mpp[text[j]]--;
                if(mpp[text[j]]==0)
                count--;
            }

            if(j-i+1<k){
                j++;
            }

            else if(j-i+1==k){

                if(count==0){
                    res++;
                }

                if(mpp.find(text[i])!=mpp.end()){
                    mpp[text[i]]++;
                    if(mpp[text[i]]==1)
                    count++;
                }

                i++;
                j++;
            }

        }
        return res;
    } 
};

int main(){
    string s1="zxcatgtac";
    string s2="cat";
    Anagram obj;
    cout<<obj.Occurence_of_Anagaram(s1,s2);
}