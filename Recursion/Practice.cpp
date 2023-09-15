// Print name 5 times

#include <bits/stdc++.h>
using namespace std;

class Names
{
public:
    int display(int n)
    {
        if(n==0){
            return 1;
        }
        return n * display(n-1);
    }
};

int main()
{
    Names obj;
    cout<<obj.display(3);
    return 0;
}