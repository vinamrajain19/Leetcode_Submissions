class Solution {
public:
    
    bool f(int i,int j,vector<vector<char>>& b,char ch){
        
        for(int col = 0;col < 9;col++){
            if(b[i][col] == ch){
                return false;
            }
        }
        
        for(int row = 0;row < 9;row++){
            if(b[row][j] == ch){
                return false;
            }
        }
        
        int row = i - i % 3;
        int col = j - j % 3;

        for(int p = row;p < row + 3;p++){
            for(int q = col;q< col + 3;q++){
                if(b[p][q] == ch) return false;
            }
        }
        
        return true;
        
    }
    
    
    bool solve(vector<vector<char>>& b){
         for(int i = 0;i<b.size();i++){
            for(int j = 0;j<b[i].size();j++){
                if(b[i][j] == '.'){
                    for(char k = '1';k<='9';k++){
                        if(f(i,j,b,k)){
                            b[i][j] = k;
                            if(solve(b)) return true;
                            else b[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& b) {
       solve(b);
    }
};