class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> line(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            line[i] = s;
        }
        vector<vector<string>> ans;
        queen(ans,line,n,0);
        return ans;
        
    }
     
    bool issafe(vector<vector<string>> &ans,vector<string> &line,int row,int col){
        // check vertical row
        for (int i = 0; i < row; i++)
        {
            if (line[i][col] == 'Q')
            {
                return false;
            }
        }
        
        // check left diagonal
        for(int i=row,j=col;i>=0&&j>=0;--i,--j)
            if(line[i][j] == 'Q') return false;
        
        //check right diagonal
        for(int i=row,j=col;i>=0&&j<line.size();--i,++j)
            if(line[i][j] == 'Q') return false;
   
        return true;
    }
    
    void queen(vector<vector<string>> &ans,vector<string> &line,int n,int row){
        //exit condition
        if(row == n){
            ans.push_back(line);
            return;

        }
        // iterate every possible position
        for(int col = 0;col<n;col++){
            if(issafe(ans,line,row,col)){
                // make decision
                line[row][col] = 'Q';
                // next iteration
                queen(ans,line,n,row+1);
                // back-tracking
                line[row][col] = '.';
            }
        }
    }
    
    
};