// Moderate Solution , Simople struing matching problem

class Solution
{
public:
    bool isAllStars(string &S1, int i)
    {
        for (int j = 0; j <= i; j++)
        {
            if (S1[j] != '*')
                return false;
        }
        return true;
    }

    bool func(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    {

        if (i < 0 && j < 0)
            return true;
        if (i >= 0 && j < 0)
            return false;
        if (i < 0 && j >= 0)
        {
            return isAllStars(p, j);
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == p[j] || p[j] == '?')
        {
            return dp[i][j] = func(s, p, i - 1, j - 1, dp);
        }
        else
        {
            if (p[j] == '*')
            {
                bool taking = func(s, p, i, j - 1, dp);
                bool nottaking = func(s, p, i - 1, j, dp);
                return dp[i][j] = taking || nottaking;
            }
            else
                return false;
        }
    }

    bool isMatch(string s, string p)
    {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        bool res = func(s, p, n - 1, m - 1, dp);
        return res;
    }
};