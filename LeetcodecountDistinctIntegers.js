//Leetcode ID : 2442                            Problem Name  : Count Number of Distinct Integers After Reverse Operations
//Level : Medium
var countDistinctIntegers = function(nums) {
    let  mp = new Map()
    let ans = []
    for(let i = 0;i<nums.length;i++){
        ans.push(reverse(nums[i]));
    }
    for(let i = 0;i<nums.length;i++){
        if(mp.has(nums[i])){
            continue;
        }else{
            mp.set(nums[i],0);
        }
    }
      for(let j = 0;j<ans.length;j++){
        if(mp.has(ans[j])){
            continue;
        }else{
            mp.set(ans[j],0);
        }
    }
    let count = 0;
    for(let k of mp){
        count++;
    }
    return count;
};
function reverse(n){
    let str = '';
    while(n>0){
        let rem = n % 10;
        str+=rem;
        n = parseInt(n / 10);
    }
    return parseInt(str);
}
