//Leetcode ID : 2441                            Problem name :  Largest Positive Integer That Exists With Its Negative
//Level : Easy

var findMaxK = function(nums) {
    let  mp = new Map();
    for(let n of nums){
           if(mp.has(n)){
                mp.set(n,mp.get(n)+1)
            }else{
                mp.set(n,1)
            }
    }
    
    let maxi = -Infinity
    for(let [k,v] of mp){
        if(parseInt(k)<0){
            if(mp.get(parseInt(-k))>=1){
                maxi = Math.max(maxi,Math.abs(k))
            }else{
                continue
            }
        }else{
            if(mp.get(parseInt(-k))>=1){
                maxi = Math.max(maxi,Math.abs(k))
            }else{
                continue
            }
        }
    }
    return maxi===-Infinity?-1:maxi;
};
