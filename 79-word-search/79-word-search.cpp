class Solution {
public:
   bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(word[0]==board[i][j] and search(board,word,i,j,0,visited)){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool search(vector<vector<char>>& board,string word,int i,int j,int idx,vector<vector<bool>> &visited){
        if(idx == word.size()){
            return true;
        }
        
        if(i<0 || i >= board.size() || j<0 || j>=board[i].size() ||idx >word.size() ||  visited[i][j] || word[idx] != board[i][j]){
            return false;
        }
        
        visited[i][j] = true;
        
        if(search(board,word,i+1,j,idx+1,visited) || search(board,word,i-1,j,idx+1,visited) || search(board,word,i,j+1,idx+1,visited) || search(board,word,i,j-1,idx+1,visited)){
            return true;
        }
        
        visited[i][j] = false;
        
        return false;
    }

};