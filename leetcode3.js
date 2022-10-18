//Leetcode ID : 3.                                  Problem name : Longest Substring Without Repeating Characters
//level : Medium

var lengthOfLongestSubstring = function(s) {
   const freqMap = new Array(256).fill(-1);
    let maxLength = 0;
    let len = 0;
    for(let i = 0;i<s.length;i++){
        if(freqMap[s[i].charCodeAt()]>=i-len){
            
            len = i-freqMap[s[i].charCodeAt()];
            
        }else{
            len++;
        }
        maxLength = Math.max(len,maxLength);
        freqMap[s[i].charCodeAt()] = i;
        
    }
    return maxLength;
};
