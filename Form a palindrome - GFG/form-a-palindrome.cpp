//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minInsertions(string s) {
        string s2 = string(s.rbegin(),s.rend());
        
        int m = s.size();
        int n = s2.size();
        
        vector<int> prev(n+1,0),curr(n+1,0);
        
        prev[0] = 0; 
        
        //main code
        for(int i = 1;i<m+1;i++){
            for(int j= 1;j<n+1;j++){
                if(s[i-1] == s2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        
        return s.size() - curr[n];
    }
    int countMin(string str){
    //complete the function here
    return minInsertions(str);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends