 //Leetcode ID : 402                                    Problem Name :  Remove K Digits
//Level : Medium                                        Related topics : Stack
 Array.prototype.isEmpty = function() {
    return this.length === 0;
}
Array.prototype.peek = function() {
    return this[this.length-1];
}

var removeKdigits = function(num, k) {
  
    // 1 4 3 2 2 1 9 choose x among some these digits 
    //1 + 1 + 1
    // 1 2 
    
    //1 0 2 0 0
    //1
    //0 2 0 0 - 200 
    
    // 4 3 2 1 9 9 , k = 3
   /* 1 + 1 + 1
    1 + 9 + 9 = 199
    */
    const stack = new Array();
    for(const char of num) {
        while(!stack.isEmpty() && k > 0 && stack.peek() > parseInt(char)) {
            stack.pop();
            k--;
        }
         if (stack.length>0 || char !='0'){
         stack.push(char)
         }
    }
   
    let result = "";
    for(let i = 0; i < stack.length - k; i++) {
            result += stack[i];
    }
    return result === "" ? "0" : result;
};
