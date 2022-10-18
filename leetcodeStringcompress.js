//leetcode ID:443                                     Problem Name :  String Compression
//Level : Medium

var compress = function(chars) {
   let  res = [];
    let check = chars[0]
    let count = 0
    for(let i = 0;i<chars.length;i++){
        if(chars[i]===check){
            count++;
        }else{
            helper(check,count,res);
            count = 1;
            check = chars[i];
        }
          if(i===chars.length-1){
        helper(check,count,res);
          }
    }
    while(chars.length!=0){
        chars.pop()
    }
    for(let c of res){
        chars.push(c)
    }
    let len = chars.length
    return len
};

function helper(check,count,res){
            let v = count;
             if(v===1){
            res.push(check)
        }else if(v<10){
           res.push(check)
            res.push(String(v))
        }else if(v>9 && v<100){
            let c = String(v)
            res.push(check)
            res.push(c[0])
            res.push(c[1])
        }else if(v>99 && v<1000){
            let c = String(v)
            res.push(check)
           res.push(c[0])
            res.push(c[1])
            res.push(c[2])
        }else{
            let c = String(v)
            res.push(check)
            res.push(c[0])
            res.push(c[1])
            res.push(c[2])
            res.push(c[3])
        }
}
