//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1e9+7;
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        
        vector<int> curr(m,0);
        
        vector<int> ahead(m,0);
        
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(i == n-1 and j == m-1 and grid[i][j] != 1){
                    curr[j] = 1;
                }
                else if(grid[i][j] == 1){
                    curr[j] = 0;
                }
                else{
                    
                    int a = 0;
                    int b = 0;
                    
                    if(i+1 < n){
                        a = ahead[j];
                    }
                    if(j+1 < m){
                        b = curr[j+1];
                    }
                    
                    curr[j] = (a+b) % mod;
                }
            }
            ahead = curr;
        }
        return curr[0] % mod;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends