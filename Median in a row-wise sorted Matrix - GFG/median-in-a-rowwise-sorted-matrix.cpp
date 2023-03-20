//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
     int cnt(vector<int> arr,int x){
        int t = 0;
        
        int s = 0;
        int e = arr.size()-1;
        
        while(s <= e){
         int m = (s+e)/2;
         
         if(arr[m] <= x){
             s = m+1;
         }
         else e = m-1;
        }
        return s;
    }
    
    int median(vector<vector<int>> &matrix, int R, int C){
        int s = 0;
        int e = 2000;
        
        int ans = 0;
        while(s <= e){
            int mid = s+(e-s)/2;
            int count = 0;
            
            for(int i = 0;i<R;i++){
                count += cnt(matrix[i],mid);
            }
            
            if(count <= (R*C)/2){
                s = mid  + 1;
            }
            else e = mid - 1;
        }
        return s;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends