// Just find the index maximum element index value

// And then that will be the number of times the array is rotated

// reason - If the maximum element is somewhere else other than its original position it means it is rotated from its original position

// T.C = O(logN)

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int low = 0,high = n-1;
        int maximum = INT_MIN;
        int index = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(arr[low] <= arr[mid]){
                if(arr[mid] >= maximum){
                    maximum = arr[mid];
                    index = mid;
                }
                low = mid+1;
            }
            else{
                if(arr[low] >= maximum){
                    maximum = arr[low];
                    index = low;
                }
                high = mid-1;
            }
        }
        return (index+1) % n;
    }
};