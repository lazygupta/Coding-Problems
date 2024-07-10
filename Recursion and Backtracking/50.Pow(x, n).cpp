class Solution {
public:

    void answer(double x,double *res,int n,int i){
        if(i >= n){
            return;
        }
        *res = *res * x;
        answer(x,res,n,i+1);
    }

    double myPow(double x, int n) {
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        double num;
        double res = 1.0;
        if(n>=0){
            answer(x,&res,n,0);
            num = res;
        } 
        else {
            n = -n;
            answer(x,&res,n,0);
            num = 1.0/res;
        } 
        return num;
    }
};

// 2nd method , Without de referencing a variable

class Solution {
public:

    double answer(double x,int n){
        if(n==0){
            return 1;
        }
        return x * answer(x,n-1);
    }

    double myPow(double x, int n) {
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        double num;
        if(n>=0){
            num = answer(x,n);
        } 
        else {
            n = -n;
            num = answer(x,n);
            num = 1.0/num;
        } 
        return num;
    }
};