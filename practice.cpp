#define ll long long

class Solution
{
public:
    int maximum(vector<int> &v)
    {
        int maximum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            maximum = max(v[i], maximum);
        }
        return maximum;
    }

    ll result(vector<int> &v, int hour_speed)
    {
        ll totalhrstaken = 0;
        for (int i = 0; i < v.size(); i++)
        {
            totalhrstaken += ceil(double(v[i]) / double(hour_speed));
        }
        return totalhrstaken;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1, high = maximum(piles);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (result(piles, mid) == h)
            {
                return mid;
            }

            if (result(piles, mid) > h)
            {
                low = mid + 1;
            }

            if (result(piles, mid) < h)
            {
                high = mid - 1;
            }
        }
        return 99765;
    }
};