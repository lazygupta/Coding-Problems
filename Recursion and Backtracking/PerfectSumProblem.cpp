// Recursive Approach
// T.C = O(2N) + O(NxM)

// Rejected because time complexity is too high

class Solution{
	public:
	
	void generate(vector<int> nums,vector<int> v,int index,vector<vector<int>> &res){
	    if(index==nums.size()){
	        res.push_back(v);
	        return;
	    }
	    v.push_back(nums[index]);
	    generate(nums,v,index+1,res);
	    v.pop_back();
	    generate(nums,v,index+1,res);
	}
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>> res;
        vector<int> nums(arr,arr+n);
        vector<int> v;
        generate(nums,v,0,res);
        int s=0,count=0;
        for(auto it:res){
            s=0;
            for(auto it1:it){
                s+=it1;
            }
            if(s==sum) count++;
        }
        return count;
	}
	  
};

// Can be solved wityh dynamic programming approach