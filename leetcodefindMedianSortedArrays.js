//Leetcode ID : 4                                              Problem Name :  Median of Two Sorted Arrays
//Level : Hard
var findMedianSortedArrays = function(nums1, nums2) {
    while(nums2.length!=0){
        let  x = nums2.pop();
        nums1.push(x);
    }
    nums1.sort((a,b)=>a-b);
    let n = nums1.length;
    if(n % 2==0){
        n = n/2;
        return (nums1[n-1]+nums1[n]) /2;
    }else{
        n = Math.floor(n/2);
        return nums1[n];
    }
};
