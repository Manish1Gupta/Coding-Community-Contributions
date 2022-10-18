//leetcode ID:1                                     Problem name : Two Sum
//level : Easy

var twoSum = function(nums, target) {
    let lo = 0;
    let hi = nums.length-1;
    let Aux = new Array(nums.length-1);
    for(let i=0;i<nums.length;i++){
        Aux[i] = [nums[i],i];
    }
    Aux.sort((a,b)=>a[0]-b[0]);
    while(lo<hi){
        if(Aux[lo][0]+Aux[hi][0]==target){
            return [Aux[lo][1],Aux[hi][1]];
        }else if(Aux[lo][0]+Aux[hi][0]>target){
            hi--;
        }else{
          ++lo;
        }
    }
    return [-1,-1];
};
