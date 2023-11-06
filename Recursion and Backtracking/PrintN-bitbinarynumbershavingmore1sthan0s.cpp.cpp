// Mast question hai

#include<bits/stdc++.h>
using namespace std;

// First make recursive tree
// Just write the same code you thought to draw recursive tree
// Check for when there is double output and when there is single output

class Solution{
public:

    void solve(vector<string> &result,int ones, int zeroes, int n, string output){
        if(n==0){
            result.push_back(output);
            return;
        }
        if(ones>zeroes){
            string op1=output;
            string op2=output;
            op1.push_back('1');
            solve(result,ones+1,zeroes,n-1,op1);
            op2.push_back('0');
            solve(result,ones,zeroes+1,n-1,op2);
        }
        else if(ones==zeroes){
            string op1=output;
            op1.push_back('1');
            solve(result,ones+1,zeroes,n-1,op1);
        }
    }

	vector<string> NBitBinary(int N)
	{
	    vector<string> res;
	    string output="";
	    int ones=0,zeroes=0;
	    solve(res,ones,zeroes,N,output);
	    return res;
	}
};

// further you can always push back 1 to string and whenever ones>zeroes you have to push back 0 too

// So above code can be of shorter code optimization

//User function template for C++
class Solution{
public:

    void solve(vector<string> &result,int ones, int zeroes, int n, string output){
        if(n==0){
            result.push_back(output);
            return;
        }
        string op1=output;
        op1.push_back('1');
        solve(result,ones+1,zeroes,n-1,op1);
        if(ones>zeroes){
            string op2=output;
            op2.push_back('0');
            solve(result,ones,zeroes+1,n-1,op2);
        }
    }

	vector<string> NBitBinary(int N)
	{
	    vector<string> res;
	    string output="";
	    int ones=0,zeroes=0;
	    solve(res,ones,zeroes,N,output);
	    return res;
	}
};


// Variety 2
// Binary strings with no consecutive 1s

// Make recursive tree and fod do code

#include<bits/stdc++.h>

void solve(vector<string> &res,int ones,int zeroes,int n,string output){
    if(n==0){
        res.push_back(output);
        return;
    }
    string op1=output;
    op1.push_back('0');
    solve(res,ones,zeroes+1,n-1,op1);
    if(output[output.length()-1] != '1'){
        string op2=output;  
        op2.push_back('1');
        solve(res,ones+1,zeroes,n-1,op2);
    }
}

vector<string> generateString(int N) {
    // Write your code here.
    vector<string> res;
    string output="";
    int ones=0,zeroes=0;
    solve(res,ones,zeroes,N,output);
    return res;
}