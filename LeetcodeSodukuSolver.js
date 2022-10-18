//leetcode ID : 37                             Problem name :  Sudoku Solver
//Level :  Hard


/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */

function solve(board){
    for(let i=0;i<9;i++){
        for(let j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(let k=1;k<=9;k++){
                    if(isValid(i,j,board,k)){
                        board[i][j]=String(k);
                        if(solve(board)){
                            return true;
                        }else{
                            board[i][j]='.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
function isValid(row,col,board,num){
    for(let  i=0;i<9;i++){
        if(board[row][i]==num){
            return false;
        }
        if(board[i][col]==num){
          return false;
        }
        if(board[3*parseInt(row/3)+parseInt(i/3)][3*parseInt(col/3)+i%3]==num){
            return false;
        }
    } 
    return true;
}
var solveSudoku = function(board) {
     solve(board);
};
