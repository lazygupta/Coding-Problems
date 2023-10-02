// The question is to put k number of gas stations in array
// Such that the maximum distance between any two gas stations is minimized

// First of all we have to think if we have to minimize the distance than the gas stations is to be put between
// the two gas stations

// e.g { 1, 13 ,17 ,23}
// 1---------13---------17----------23
// | section1|| section2|| section3 |

// We just store the section length with their index in priority queue
// Put 1st gas station between 1 and 13
// 1-----x-----13----------17----------23
// |  6     6  ||    4      |     6     |
//                                                                          | 6,2   |
//                                                                          | 6,0   |
//                                                                          | 4,1   |
//                                                                          |_______|

// Like above the heap structure will continuously adjust itself according  to the priority

// 3,2
// 3,0
// 2,1


// T.C = O(NlogN) + O(KlogN)
// S.C = O(N-1)


#include <bits/stdc++.h>
using namespace std;

double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.
	int howMany[arr.size()-1]={0};
	priority_queue<pair<long double , int>> pq;
	for(int i=0;i<arr.size()-1;i++){
          pq.push({arr[i + 1] - arr[i], i});
    }
	for(int i=1;i<=k;i++){
		auto section=pq.top();
		pq.pop();
		int section_index = section.second;
		howMany[section_index]++;
		long double diff = arr[section_index + 1] - arr[section_index] ;
		long double number_of_section = diff / (long double) (howMany[section_index] +1);
		pq.push({number_of_section , section_index});
	}

	return pq.top().first;
}
