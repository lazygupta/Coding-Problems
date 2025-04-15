// So we have to check the parioty of the sum of two adjacent elements
// If the sum is even then we have to return false
// If the sum is odd then we have to return true


// According to the matehmatical definition : - Sum of a odd and even number is alwas a odd
// difference between an even and an odd number is odd. 
// product of an even and an odd number is even. 

function isArraySpecial(nums: number[]): boolean {
    if(nums.length === 1) return true

    for(let i = 1; i< nums.length ; i++) {
      if((nums[i] + nums[i-1]) % 2 !== 1) return false
    }
    return true
};

// 2nd method

// Comparing the parity of the adjacent element
// If the parity is same then we have to return false , because if both numbers are even or both are odd they will have same parity

function isArraySpecial(nums: number[]): boolean {
    for(let i = 0; i<nums.length-1 ;i++) {
      if(nums[i] % 2 == nums[i+1]%2) return false
    }
    return true
};

// 3rd method
// Same as 2nd method but using XOR
// Using the XOR operator to check the parity of the adjacent element

// XOR of same number is always 0
// We will find the parity of first ele and second ele, Will XOR the value , if the value comes to 0 then both parity are same
// means that the number is of same type wither odd or even

function isArraySpecial(nums: number[]): boolean {
    for(let i = 1;i<nums.length;i++){
      if(((nums[i] & 1) ^ (nums[i-1] & 1)) == 0) return false
    }
    return true
};