//Leetcode ID : 46                                Problem Name :  Permutations
//Level : Medium                                  Related Topics : Array , BackTracking
function helper(arr,start,res){
    //base case
    if(start>=arr.length){
        res.push([...arr])
        return;
    }
      for(let i=start;i<arr.length;i++){
          swap(arr,start,i)
          helper(arr,start+1,res);
          swap(arr,start,i)
      }
}
function swap(arr,v1,v2){
    let temp =arr[v1];
    arr[v1] = arr[v2];
   arr[v2]= temp;
}
var permute = function(nums) {
    let res = [];
    helper(nums,0,res);
    return res;
};
