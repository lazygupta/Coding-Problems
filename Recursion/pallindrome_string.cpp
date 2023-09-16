#include <bits/stdc++.h>
using namespace std;

class Thunder
{
public:
    bool pallindrome(int i, string s, int n)
    {
        if (i >= (n / 2))
            return true;
        if (s[i] != s[n - i - 1])
            return false;
        return pallindrome(i + 1, s, n);
    }
};

int main()
{
    Thunder obj;
    string s = "MADAM";
    if (obj.pallindrome(0, s, s.length()))
        cout << "Pallindrome";
    else
        cout << "Not Pallindrome";
    return 0;
}