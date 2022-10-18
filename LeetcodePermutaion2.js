//Leetcode ID : 47.                   Problem Name :  Permutations II
//Level :  Medium                     Related Topics : Array , BackTracting


function helper(arr,mp,start){
    if(start>=arr.length){
        mp[[...arr].join('')] = [...arr]
        return;
    }
    for(let i=start;i<arr.length;i++){
        swap(arr,i,start);
        helper(arr,mp,start+1);
        swap(arr,i,start);
    }
}
function swap(arr,i,j){
    let temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
var permuteUnique = function(nums) {
    let mp = {};
    helper(nums,mp,0);
    return Object.values(mp)
};
