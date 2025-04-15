// Simple by seeing the question it can be solved by taking max ele from the arrays everytime and adding to score
// After adding to score , we have to increase the max_num by 1 and decerease the k operations by 1

// Time complexity: O(n)
// Space complexity: O(1)

function maximizeSum(nums: number[], k: number): number {
    let max_num: number = Math.max(...nums)
    let score: number = 0
    while(k!=0){
      score += max_num
      max_num += 1
      k--
    }
    return score
};


// Trying mor eoptimized way
// So we know the formula for sum of n numbers is n*(n+1)/2
// So we can use this formula to calculate the sum of k numbers starting from max_num
// So the sum of k numbers starting from max_num is k*(max_num + (max_num + k - 1))/2


function maximizeSum(nums: number[], k: number): number {
    const max_num: number = Math.max(...nums)
    return k*max_num + (k*(k-1))/2
};

// How this works?
// So we know the formula for sum of n numbers is n*(n+1)/2
// Now suppose k = 3
// So the answer for this array = [1,2,3,4,5] is 5 + 6 + 7 = 18

// That is 5 + (5+1) + (5+2) 
// 5 + 5 + 5 + (0+1+2)
// 3*5 + Sum of n-1 natural numbers
// So it becomes k*max_num + (k*(k-1))/2
