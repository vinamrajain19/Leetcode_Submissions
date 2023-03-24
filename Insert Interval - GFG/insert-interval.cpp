//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ni) {
        vector<vector<int>> ans;
        
        int i = 0;
        
        
        // case 1 till where have not had the pos for new interval;
        while(i < in.size() and in[i][1] <  ni[0]){
            ans.push_back(in[i]);
            i++;
        }
        
        
        // case 2-> we have got the pos for new interval
        while(i < in.size() and in[i][0] <= ni[1]){
            ni[0] = min(in[i][0],ni[0]);
            ni[1] = max(in[i][1],ni[1]);
            i++;
        }
        
        ans.push_back(ni);
        
        // case 3 -> now put all in as it is
        
        while(i < in.size()){
            ans.push_back(in[i]);
            i++;
        }
        
        return ans;
        
        
    }
    
    vector<vector<int>> insertNewEvent(int N, vector<vector<int>> &intervals, vector<int> &newEvent) {
        // code here
        return insert(intervals,newEvent);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N,vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0]>>intervals[i][1];
        }
        vector<int> newEvent(2);
        cin>>newEvent[0]>>newEvent[1];
        
        Solution obj;
        vector<vector<int>> ans = obj.insertNewEvent(N, intervals,newEvent);
        cout<<"[";
        for(int i=0;i<ans.size();i++){
            cout<<"["<<ans[i][0]<<','<<ans[i][1]<<']';
            if(i!=(ans.size()-1)) cout<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
// } Driver Code Ends