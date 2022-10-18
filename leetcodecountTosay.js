// leetcode ID : 38                               Problem name : Count and Say
//level : Medium                                  Related topic : string


var countAndSay = function(n) {
 //steps . 1 while 
 // steps . 2 keep consicutive numbers
    let  s = "1";
    while(n>1){
        let  newStr = "";
        let count = 0;
        let say = s[0];
        for(let i = 0;i<s.length;i++){
            if(say===s[i]){
                count+=1;
            }else{
                newStr+=count+say;
                count = 1;
                say = s[i];
            }
        }
        s = newStr+count+say;
        n--;
    }
    return s;
}; 
