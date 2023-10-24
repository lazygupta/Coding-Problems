#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &v, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (v[left] <= v[right])
            {
                temp.push_back(v[left]);
                left++;
            }
            else
            {
                temp.push_back(v[right]);
                right++;
            }
        }
        while (left <= mid)
        {
            temp.push_back(v[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(v[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
        {
            v[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int> &v, int low, int high)
    {
        if (low >= high)
        {
            return;
        }
        int mid = (low + high) / 2;
        mergeSort(v, low, mid);
        mergeSort(v, mid + 1, high);
        merge(v, low, mid, high);
    }

    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};