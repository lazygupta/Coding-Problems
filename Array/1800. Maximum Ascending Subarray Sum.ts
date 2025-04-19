// Just check the next element is greater than the previosu ele or not
// If the condition satisfies just add it into sum
// if the condition fails store the maximum_sum and reset the sum value to be 0

function maxAscendingSum(nums: number[]): number {
    let i: number = 0
    let sum: number = 0
    let max_num: number = 0
    while(i < nums.length){
      sum += nums[i]
      if(nums[i] < nums[i+1]){
        i++;
      } else {
        max_num = Math.max(max_num, sum)
        sum = 0
        i++
      }
    }
    return max_num
};

// Same method
// More concise

function maxAscendingSum(nums: number[]): number {
    let i: number = 1
    let sum: number = nums[0]
    let max_sum: number = 0
    while(i < nums.length){
      if(nums[i] <= nums[i-1]){
        max_sum = Math.max(max_sum,sum)
        sum = 0
      }
      sum += nums[i]
      i++
    }
    return Math.max(sum,max_sum)
};