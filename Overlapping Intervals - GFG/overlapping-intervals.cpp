//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>> ans;
        
        sort(in.begin(),in.end(),cmp);
        
        vector<int> t = in[0];
        
        for(int i = 1;i<in.size();i++){
            if(t[1] < in[i][0]){
                ans.push_back(t);
                t = in[i];
            }
            else{
                t[0] = min(t[0],in[i][0]);
                t[1] = max(t[1],in[i][1]);
            }
            
            
        }   
        
        ans.push_back(t);
        return ans;
    }

    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         return merge(intervals);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends