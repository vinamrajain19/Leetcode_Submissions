class Solution {
public:
    
   /*   Approach
First we will find the subarrays that contribute to sum equal to target, considering each row.

| a | b | c | ------------------row1
| d | e | f | ------------------row2
| g | h | i |-------------------row3

Combine consecutive rows and find answer again, as submatrix can also combination of two or more rows.

| a | b | c | ------find for this
| d+a | e+b | f+c | -----find for this row
| g+d+a | h+e+b | i+f+c | ------find for this row

similarly,

| d | e | f | -----for this row
| g+d | h+e | i+f | -----for this row

and,
| g | h | i | -----for this row

add the answers of all these rows, and have the final answer */
    
    int f(vector<int> &v,int tar){
        unordered_map<int,int> m;
        m[0] = 1;
        int sum = 0;
        int ans = 0;
        
        for(auto it : v){
            sum += it;
            ans += m[sum-tar];
            m[sum]++;
        }
        
        return ans;
    }
    
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
        
        for(int i = 0;i<matrix.size();i++){
            
            vector<int> prefixsum(matrix[0].size(),0);
            
            for(int j = i;j<matrix.size();j++){
                
                for(int k = 0;k<matrix[0].size();k++){
                    
                    prefixsum[k] += matrix[j][k];
                    
                }
                
                ans += f(prefixsum,target);
            }
        }
        
        return ans;
    }
};