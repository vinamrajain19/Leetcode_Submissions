class Solution {
public:
    
    int ans = 0;
    
    bool issafe(int i,int j,vector<string> &v){
        
        // upside
        for(int k = 0;k<i;k++){
            if(v[k][j] == 'Q') return false;
        }
        
        //left diagonal
        for(int k = i,m = j; k >=0 and m>=0; k--,m--){
            if(v[k][m] == 'Q') return false;
        }
        
        //right diagonal
        for(int k = i,m = j; k >= 0 and m<v.size(); k--,m++){
            if(v[k][m] == 'Q') return false;
        }
        
        return true;
    }
    
    void f(int n,vector<string> &v,int idx){
        if(idx == n){
            ans++;
            return;
        }
        
        for(int j = 0;j<n;j++){
            if(issafe(idx,j,v)){
                v[idx][j] = 'Q';
                f(n,v,idx+1);
                v[idx][j] = '.'; //backtrack
            }
        }
    }
    
    
    int totalNQueens(int n) {
         vector<string> v(n);
        string s(n,'.');
        
        for(int i = 0;i<n;i++){
            v[i] = s;
        }
        
        f(n,v,0);
        return ans;
    }
};