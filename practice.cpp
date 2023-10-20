#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 50;
    int flag = 0, i = 0, j = 0;
    for (i = 2; i <= n; i++)
    {
        flag = 0;
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << i << " ";
        }
    }

    return 0;
}