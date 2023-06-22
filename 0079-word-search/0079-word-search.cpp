class Solution {
public:
    
    bool f(vector<vector<char>> &b,string &w,vector<vector<int>> &vis,int idx,int i,int j){
         if(idx == w.size()) return true;
        
         if(i < 0 or j < 0 or i >= b.size() or j>= b[0].size() or w[idx] != b[i][j] or vis[i][j] == 1) return false;
        
        vis[i][j] = 1; 
        
        bool a = f(b,w,vis,idx+1,i+1,j);
        bool ba = f(b,w,vis,idx+1,i-1,j);
        bool c = f(b,w,vis,idx+1,i,j+1);
        bool d = f(b,w,vis,idx+1,i,j-1);
        
        vis[i][j] = 0;
        
        return a or ba or c or d;
    }
    
    bool exist(vector<vector<char>>& b, string w) {
        for(int i = 0;i<b.size();i++){
            for(int j = 0;j<b[0].size();j++){
                if(b[i][j] == w[0]){
                    vector<vector<int>> vis(b.size(),vector<int>(b[0].size(),0));
                    if(f(b,w,vis,0,i,j)) return true;
                }
            }
        }
        
        return false;
    }
};