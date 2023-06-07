class Solution {
public:
    
    
    bool isValid(vector<vector<char>>& board, int row, int col){
        int c = board[row][col];
        board[row][col] = '.';
        for(int i=0;i<9;i++)
            if(board[row][i] == c) return false;
        for(int i=0;i<9;i++)
            if(board[i][col] == c) return false;
        
        int x = (row/3) * 3;
        int y = (col/3) * 3;
        for(int i=x;i<x+3;i++)
            for(int j=y;j<y+3;j++)
                if(board[i][j] == c)
                    return false;
        
        board[row][col] = c;
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
    
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.' && !isValid(board,i,j)){
                    return false;
                }
            }
        }
        return true;
    }
};