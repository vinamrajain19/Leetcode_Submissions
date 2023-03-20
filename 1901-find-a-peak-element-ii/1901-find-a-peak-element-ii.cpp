class Solution {
public:
    
     vector<int> findPeakGrid( vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int beg = 0, end = n - 1;
        while(beg <= end)
        {
            int mid = (beg + end) >> 1;
            
            int j = distance(mat[mid].begin(),max_element(mat[mid].begin(),mat[mid].end()));
            
            //The distance function is used to find index of max element.
            
            
            if((mid-1)>=0 && mat[mid-1][j]>mat[mid][j])
                end = mid - 1;
            else if((mid+1)<n && mat[mid+1][j]>mat[mid][j])
                beg = mid + 1;
            else
                return {mid,j};
        }
        return {};
    }
};