//Leetcode ID : 52                                         Problem name :  N-Queens II
//level : Hard
/**
 * @param {number} n
 * @return {number}
 */
var totalNQueens = function(n) {
    let ans = [];
    let board = new Array(n);
    for(let i=0;i<n;i++){
        board[i] = new Array(n).fill(0);
    }
 function checkSafe(row,col,board){
        let nextRow = row;
        let nextCol = col;
        //check left side
        while(nextCol>=0){
            if(board[nextRow][nextCol]=='Q'){
                return false;
            } 
            nextCol--;
        }
         nextRow = row;
         nextCol = col;
        //upward diagonal check
        while(nextRow>=0 && nextCol>=0){
            if(board[nextRow][nextCol]=='Q'){
                return false;
            }
            nextRow--;
            nextCol--;
        }
        //downward diagonal check
         nextRow = row;
         nextCol = col;
        while(nextRow<n && nextCol>=0){
            if(board[nextRow][nextCol]=='Q'){
                return false;
            }
            nextRow++;
            nextCol--;
        }
        return true;
    }
    function solve(col,board){
        if(col==n){
            ans.push(board.map(ele=>ele.join('')));
            return
        }else{
            for(let i=0;i<n;i++){
                if(checkSafe(i,col,board)){
                    board[i][col]='Q';
                    solve(col+1,board);
                    board[i][col]=0;
                }
            }
        }
    }
    solve(0,board);
    return ans.length;
};
