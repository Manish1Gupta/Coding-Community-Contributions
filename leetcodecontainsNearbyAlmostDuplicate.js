//leetcode ID : 220                                        Problem name :  Contains Duplicate III
//level :  hard 
var containsNearbyAlmostDuplicate = function(nums, k, t) {
for(let i =0;i<nums.length;i++){
    for(let j = i+1;j<nums.length;j++){
        if((Math.abs(nums[i]-nums[j])<=t) && (Math.abs(i-j)<=k)){
            return true;
        }
    }
}
    return false;
};
