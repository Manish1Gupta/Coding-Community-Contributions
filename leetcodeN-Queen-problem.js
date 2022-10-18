//Leetcode ID :  51                                                  Problem Name :  N-Queens
//level : Hard 
var solveNQueens = function(n) {
    let arr = [];
    let board = new Array(n)
    for(let i=0;i<n;i++){
        board[i] = new Array(n).fill('.')
    }
 function checkSafe(row,col,board){
        let dupCol = col;
        let dupRow = row;

        //         check left
       while(dupCol>=0) {
           if(board[dupRow][dupCol] === "Q") return false
           dupCol--;
       }
        
    dupRow = row;
    dupCol = col
        
        // check downward diagonal
        while(dupCol>=0 && dupRow < n){
            if(board[dupRow][dupCol] === "Q") return false
           dupCol--;
            dupRow++;
        }
    
    dupRow = row;
    dupCol = col
        
        // check upward diagonal
        while(dupCol>=0 && dupRow >=0){
            if(board[dupRow][dupCol] === "Q") return false
           dupCol--;
            dupRow--;
        }
        
        return true
    }
    function solve(col,board){
        if(col===n){
            arr.push(board.map(ele=>ele.join('')));
            return
        }else{
            for(let row=0;row<n;row++){
            if(checkSafe(row,col,board)){
                board[row][col]='Q';
                solve(col+1,board)
                board[row][col]='.'
            }
        }
        }
        
        
        
    }
    solve(0,board);
    return arr;
};
