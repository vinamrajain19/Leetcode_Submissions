//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int characterreplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int maxc = 0;
        int ans = 0;
        
        unordered_map<int,int> m;
        
        while(j < s.size()){
            m[s[j]]++;
            maxc = max(maxc,m[s[j]]);
            
            while(j-i+1 - maxc > k and i < s.size()){
                m[s[i]]--;
                i++;
            }
            
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
    int characterReplacement(string S, int K) {
        // code here
        return characterreplacement(S,K);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;

        Solution obj;
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends