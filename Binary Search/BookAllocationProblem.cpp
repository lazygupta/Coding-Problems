// We have to distribut the books to all students
// such that there is maximum number of pages
// Distribute in different ways and fidn the minimum of the maximum pages

// As the answers we can predict between 1 and total number of pages or maximum number of pages to total number of pages

// We will traverse from 1 to sum of elements
// Allocate dthe maximum pages to each student
// At the end if the no student is left out then store that maximum and proceed with the next
// If the students are not accomodate dthan choose lesser number of pages 

#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr,int pages){
    int stud=1;long long allocated = 0;
    for(int i=0;i<arr.size();i++){
        if( allocated + arr[i] <= pages){
            allocated+=arr[i];
        }
        else {
            stud++;
            allocated = arr[i];
        }
    }
    return stud;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n) return -1; 
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low<=high){

        int mid =( low + high )/2;
        
        if(countStudents(arr,mid) > m){
            low=mid+1;
        }

        else high = mid-1;
    }
    return low;
}