// IBM Question


#include<bits/stdc++.h>
using namespace std;

string solve(string str){
    int length= str.length();
    reverse(str.begin(),str.end());
    // cout<<str;
    int i=0;
    string res="";
    while(i<length-1){
        string x = str.substr(i,2);
        if( stoi(x) == 32){
            res += " ";
        }
        else if( ( stoi(x) >= 65 && stoi(x) <= 90) || (stoi(x) >= 97 && stoi(x) < 100)){
            res += char(stoi(x));
        }
        else if ( i+2 < length-1){
            x += str[i+2];
            i+=1;
            res += char(stoi(x));
        }
        i+=2;
    }
    return res;
}


int main(){
    string str="796115110113721110141108";
    cout<<solve(str);
    return 0;
}