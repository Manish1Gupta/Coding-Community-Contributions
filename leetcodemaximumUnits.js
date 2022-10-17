//leetcode ID : 1710.      Pronlem Name :  Maximum Units on a Truck        level : Esay 
//Related Topics ---> Greedy , Sorting , Array
var maximumUnits = function(box, size) {
    box.sort((a,b)=>{
        return b[1]-a[1];
    });
    let  count = size;
    let res = 0;
    for(let i=0;i<box.length;i++){

            if(box[i][0]<count){
                
                count = count - box[i][0];
                res += (box[i][0]*box[i][1])
            }else{
                res+=count*box[i][1];
                count-=count;
            }
    }
    return  res;
};
