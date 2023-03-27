//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
     int maximumPoints(vector<vector<int>>&nums, int n)
{
        // Code here
        for(int i=n-2;i>=0;i--)
        {
            nums[i][0]+=max(nums[i+1][1],nums[i+1][2]);
            nums[i][1]+=max(nums[i+1][0],nums[i+1][2]);
            nums[i][2]+=max(nums[i+1][0],nums[i+1][1]);
        }
      return max({nums[0][0],nums[0][1],nums[0][2]});
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends