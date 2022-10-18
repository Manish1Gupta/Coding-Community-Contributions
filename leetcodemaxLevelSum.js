//Leetcode ID : 1161                                             Problem Name : Maximum Level Sum of a Binary Tree
//Level : Medium                                                 DS : Tree

var maxLevelSum = function(root) {
    if(root.left==null && root.right==null){
        return root.val;
    }
    let  queue = [root];
    let level = 1;
    let res = []
    
    let maxi = [-Infinity,0];
    while(queue.length > 0){
        let size  = queue.length;
         let sum = 0
        while(size-->0){
            let curr = queue.shift();
            sum+=curr.val
            if(curr.left!==null){
                queue.push(curr.left);
            }
            if(curr.right!==null){
                queue.push(curr.right);
            }
        }
              if(maxi[0]<sum){
            maxi = [sum,level];
        }
     level++
    }
    return maxi[1];
};
