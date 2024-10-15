// Start itearting from back
// Because we always know that the largest amont both will be at positioning from last
// If nums1 size is 0 then only we have to swap the nums2 to nums1

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1;
        int k = m+n-1;
        if(i<0) { // returning from here after swapping as soon as we see nums1 size is 0
            nums1 = nums2;
            return;
        }
        while(j>=0){
            if(i>=0 && nums1[i] > nums2[j]){
                nums1[k]=nums1[i];
                i--;
                k--;
            } else {
                nums1[k]=nums2[j];
                k--;
                j--;
            }
        }
    }
};