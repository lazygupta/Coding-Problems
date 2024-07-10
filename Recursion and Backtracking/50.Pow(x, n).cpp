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