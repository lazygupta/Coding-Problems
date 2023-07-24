

#include<bits/stdc++.h>
using namespace std;
class Result {
    public:
        int  Longest_Maximum_Subarray(vector<int> v,int k){
            int i=0, j=0;
            int sum = 0,maximum = INT_MIN;
            while(j<v.size()){
                sum+= v[j];


                if(sum==k){
                    maximum = max (maximum , j-i+1);
                    j++;
                }

                else if(sum<k){
                    j++;
                }

                // { -2, 1, -3, 4, -1, 2, 1, -5, 4}

                

                else if(sum>k){
                    while(sum>k){
                        sum-=v[i];
                        i++;
                    }
                        if(sum==k){
                            maximum = max ( maximum , j-i+1);
                        }
                    j++;
                }
            }
                return maximum;
        }
};


int main()
{
    int k=4;
    Result obj;
    vector<int> v {-5, 8, -14, 2, 4, 12};
    // vector<int> v1=obj.FirstNegative(v, k);
    // for(auto it:v1){
        cout<<obj.Longest_Maximum_Subarray(v, k);
    // }
    return 0;
}