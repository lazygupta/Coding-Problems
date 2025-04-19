// Optimised Approach

class Solution {
    public:
      int getSecondLargest(vector<int> &arr) {
          // code here
          int largest = -1, secondLargest = -1;
          for(auto it: arr){
              if(it> largest) {
                  secondLargest = largest;
                  largest = it;
              }
              else if(it > secondLargest && it!= largest){
                  secondLargest = it;
              }
          }
          return secondLargest;
      }
  };