// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string text1){
		int m = text1.size();
        int n = text1.size();
        string text2 = text1;
        
        vector<int> prev(n+1,0),curr(n+1,0);
        
        prev[0] = 0; 
        
        for(int j = 0;j<=n;j++){
            prev[j] = 0;
        }
        
        //main code
        for(int i = 1;i<m+1;i++){
            for(int j= 1;j<n+1;j++){
                if(text1[i-1] == text2[j-1] and i != j){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        
        return prev[n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends