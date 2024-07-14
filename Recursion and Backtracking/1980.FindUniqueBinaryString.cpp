// Just like generating all binary strings and then printing any one of them which is not there already

typedef long long int ll;
class Solution {
public:

    void generateBinaryString(int size,string res,ll length,vector<string> &bucket){
        if(length == size){
            bucket.push_back(res);
            return;
        }
        res.push_back('0');
        generateBinaryString(size,res,length+1,bucket);
        res.pop_back();
        res.push_back('1');
        generateBinaryString(size,res,length+1,bucket);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int> mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        vector<string> bucket;
        generateBinaryString(nums[0].size(),"",0,bucket);
        for(int i=0;i<bucket.size();i++){
            if(find(nums.begin(),nums.end(),bucket[i]) == nums.end())
                return bucket[i];
        }
        return "-1";
    }
};

// Mind Blowing Approach

// Catch - Since we are given that number of bits in the number is equal to number of elements., we can use
// Cantor's diagonal argument 

// It states that there are infinite sets which cannot be put into one-to-one correspondence with the infinite set of natural numbers
// If s1, s2, ... , sn, ... is any enumeration of elements from T,[note 3] then an element s of T can be constructed that doesn't correspond to any sn in the enumeration.
// The proof starts with an enumeration of elements from T, for example

// s1 =	(0,	0,	0,	0,	0,	0,	0,	...)
// s2 =	(1,	1,	1,	1,	1,	1,	1,	...)
// s3 =	(0,	1,	0,	1,	0,	1,	0,	...)
// s4 =	(1,	0,	1,	0,	1,	0,	1,	...)
// s5 =	(1,	1,	0,	1,	0,	1,	1,	...)
// s6 =	(0,	0,	1,	1,	0,	1,	1,	...)
// s7 =	(1,	0,	0,	0,	1,	0,	0,	...)
// ...
// Next, a sequence s is constructed by choosing the 1st digit as complementary to the 1st digit of s1 (swapping 0s for 1s and vice versa), the 2nd digit as complementary to the 2nd digit of s2, the 3rd digit as complementary to the 3rd digit of s3, and generally for every n, the nth digit as complementary to the nth digit of sn. For the example above, this yields

// s1	=	(.0.,	0,	0,	0,	0,	0,	0,	...)
// s2	=	(1,	.1.,	1,	1,	1,	1,	1,	...)
// s3	=	(0,	1,	.0.,	1,	0,	1,	0,	...)
// s4	=	(1,	0,	1,	.0.,	1,	0,	1,	...)
// s5	=	(1,	1,	0,	1,	.0.,	1,	1,	...)
// s6	=	(0,	0,	1,	1,	0,	.1.,	1,	...)
// s7	=	(1,	0,	0,	0,	1,	0,	.0.,	...)
// ...
// s	=	(1,	0,	1,	1,	1,	0,	1,	...)
// By construction, s is a member of T that differs from each sn, since their nth digits differ (highlighted in the example). Hence, s cannot occur in the enumeration.

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res ="";
        for(int i=0;i<nums.size();i++){
            res.push_back(nums[i][i]=='0'?'1':'0');
        }
        return res;
    }
};