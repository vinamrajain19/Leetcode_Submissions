class Solution {
public:
    int t[51][51];
    int solve(vector<int>&arr,int i,int j){
        if(i>=j) return 0;
        
        if(t[i][j] != -1){
            return t[i][j];
        }
        
        int mn = 1e9;
        for(int k = i;k<j;k++){
            int temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1] * arr[k] * arr[j];
            
            mn = min(mn,temp);
        }
        
        
        return t[i][j] = mn;
    }
    int minScoreTriangulation(vector<int>& arr) {
        int n = arr.size();
        memset(t,-1,sizeof(t));
        return solve(arr,1,n-1);
    }
};
