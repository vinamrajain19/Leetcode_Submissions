//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  long long maxscore(vector<int>& card, int k) {
        int n = card.size();
        long long sum = 0;
        for(auto it : card) sum += it;
        
        int i = 0;
        int j = 0;
        long long mn = 1e9;
        long long x = 0;
        
        if(k == n) return sum;
        
        while(j < card.size()){
            x += (long long)card[j];
            
            if(j-i+1 < n - k){
                j++;
            }
            else if(j-i+1 == n-k){
                mn = min(mn,x);
                //cout<<mn<<" ";
                x -= (long long)card[i++];
                j++;
            }
        }
        
        long long t = sum - mn;
        return t;
    }
    long long maxScore(vector<int> &cardPoints, int N, int k) {
        // code here
        return maxscore(cardPoints,k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends