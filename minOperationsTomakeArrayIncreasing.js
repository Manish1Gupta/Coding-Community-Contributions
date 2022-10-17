
//LeetCode ID : 1827.                Problem Name : Minimum Operations to Make the Array Increasing
//Level : Easy                       Related Topics : Array  , Greedy

var minOperations = function(nums) {
    let output = 0;
    for(let i=0;i<nums.length-1;i++){
        if(nums[i]<nums[i+1]){
            continue;
        }else{
            output = output+(nums[i] + 1 - nums[i+1]);
            nums[i+1] = nums[i]+1
        }
    }
    return output;
};
