class Solution {
public:
 vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int>res;
    int i = 0, j = 0, dir = 0;
    res.push_back(mat[0][0]);
    while(i != m-1 || j != n-1) {
        if(dir == 0) {   // Moving top-right
            if(j == n-1) 
                i++, dir = 1;   // Move down and change direction
            else if(i == 0) 
                j++, dir = 1;   // Move right and change direction
            else 
                i--, j++;       // Move in top-right manner
        }
        else {    // Moving bottom-left
            if(i == m-1) 
                j++, dir = 0;   // Move right and change direction
            else if(j == 0) 
                i++, dir = 0;   // Move down and change direction
            else  
                i++, j--;       // Move in bottom-left manner
        }   
        res.push_back(mat[i][j]);    
    }
    return res;
}
};