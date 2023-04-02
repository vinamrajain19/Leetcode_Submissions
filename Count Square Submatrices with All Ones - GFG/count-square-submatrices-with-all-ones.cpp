//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int countsquares(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        int ans = 0;
        
        for(int i = 0;i<m;i++){
            
            for(int j = 0;j<n;j++){
                
                if(i == 0 or j == 0){
                    dp[i][j] = mat[i][j];
                }
                else if(mat[i][j]== 1){
                    dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }else{
                    dp[i][j] = 0;
                }
                
                ans += dp[i][j];
            }
        }
        
        return ans;
    }
    int countSquares(int N, int M, vector<vector<int>> &matrix) {
        // code here
        return countsquares(matrix);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> matrix(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.countSquares(N, M, matrix) << endl;
    }
    return 0;
}
// } Driver Code Ends