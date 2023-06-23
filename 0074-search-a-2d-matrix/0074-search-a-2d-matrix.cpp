class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int s = 0;
        int e = m*n-1;
        
        while(s <= e){
            int mid = (s+e)/2;
            
            int val = matrix[mid/n][mid%n];
            
            if(val == target) return true;
            else if(val > target){
                e = mid-1;
            }
            else s = mid+1;
        }
        return false;
    }
};