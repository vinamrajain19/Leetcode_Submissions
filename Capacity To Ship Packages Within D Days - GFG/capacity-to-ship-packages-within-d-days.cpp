//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  
     bool f(vector<int> &w,int days,int val){
        int c = 0;
        int ans = 1;
        int i = 0;
        while(i<w.size()){
           if(w[i] > val) return false;
           if(c + w[i] <= val){
               c += w[i];
           }
           else{
               ans++;
               c = w[i];
           }
           i++;
        }
        
        if(ans <= days) return true;
        return false;
    }
    
    int shipWithinDays(vector<int>& w, int days) {
        int sum = 0;
        for(auto it : w) sum += it;
        
        int s = 1;
        int ans = 0;
        int e = sum;
        
        while(s<=e){
            int m = (s+e)/2;
            if(f(w,days,m)){
                ans = m;
                e = m-1;
            }
            else s = m+1;
        }
        return ans;
    }
    
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        vector<int> v;
        for(int i = 0;i<N;i++) v.push_back(arr[i]);
        
        return shipWithinDays(v,D);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends