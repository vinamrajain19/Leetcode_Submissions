class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int m = mat.size();
        int n = mat[0].size();
        int i = 0;
        int j = m*n-1;
        
        while( i <= j){
            int m = i + (j-i)/2;
            
            int v = mat[m/n][m%n];
            
            if(t == v) return true;
            else if( t < v) j = m-1;
            else i = m+1;
        }
        
        return false;
    }
};