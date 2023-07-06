// So, The prblm states that you are given with an array of +ve and -ve numbers
// You just have to store all the maximum elements of all the subarrays of size k in an seperate array

//As we all know by seeing subarrays questions we can do it using Sliding Window Algorithm
// O(n+k) , where n is the size of the array and k is variable because I am shifting the 
//sliding window everytime when arr[i] is equal to max ele

// This problem can be solve in O(n*k) by using Brute Force i.e., Nested for loop
// Here I am proceeding with the most optimal solution

//Auxillary Space = O(n-1) , n is the size of the array 

// This is done by me.

#include<bits/stdc++.h>
using namespace std;

vector<int> Maximum_Elements(int arr[], int n,int k){
    int i=0,j=0;
    int max_ele=INT_MIN;
    int sum=0;
    vector<int> v;
    while(j<n){
        if(arr[j]>max_ele){
            max_ele=arr[j];
        }

        if(j-i+1<k) j++;

        else if(j-i+1==k){ // Reaching the window size
            v.push_back(max_ele); //Pushing the maximum element uin that window

            if(max_ele == arr[i]){
                max_ele=0;
                j=i+1; //This is increasing my time complexity 
                i++; 
            }
            else{
            i++;
            j++;}
        }

    }
    return v;
}

int main(){
    int n=6;
    int arr[n]={0,4,1,0,6,3};
    int k=3;
    vector<int> v1=Maximum_Elements(arr,n,k);
    for(auto &it:v1)
    cout<<it<<" ";
    return 0;
}


// Now I will try to do my problem in O(n) complexity
// I will try to use List STL 

//So , This question troubled me a lot, Done it by using Sliding window only buit with less complexity
// Aditya Verma video helped me
// In this optimal solution you have to keep track of maximum elements evrytime when arr[i] is removed.


#include<bits/stdc++.h>
using namespace std;

vector<int> Maximum_Elements(vector<int> arr,int k){
    int i=0,j=0;
    int max_ele=0;
    int sum=0;
    vector<int> v;
    list<int> l;
    while(j<arr.size()){
        // l.push_back(arr[j]);
        while(l.size()>0 && l.back()<arr[j]){
            l.pop_back();
        }
        l.push_back(arr[j]);

        if(j-i+1<k) j++;

        else if(j-i+1==k){ // Reaching the window size
            v.push_back(l.front()); //Pushing the maximum element uin that window

            if(l.front() == arr[i]){
                l.pop_front();
            }
            i++;
            j++;
            
        }
    }
    return v;
    }


int main(){
    int n=6;
    vector<int> arr={0,4,1,0,6,3};
    int k=3;
    vector<int> v1=Maximum_Elements(arr,k);
    for(auto &it:v1)
    cout<<it<<" ";
    return 0;
}