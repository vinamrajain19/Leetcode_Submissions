//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  int minEatingSpeed(vector<int>& p, int h) {
        int s = 1;
        int e = *max_element(p.begin(),p.end());
       

        while(s<e){
            int m = (s+e)/2;
            
            int x = 0;
            for(int i= 0;i<p.size();i++){
                x += (p[i]/m);
                if(p[i]%m) x++;
            }
            
            
            if(x <= h){
                e = m;
            }
            else s = m+1;
        }
        return s;      
    }
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        return minEatingSpeed(piles,H);
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends