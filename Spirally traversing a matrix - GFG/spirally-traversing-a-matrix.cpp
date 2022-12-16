//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> ans;
        int rs = 0;
        int re = r-1;
        int cs= 0;
        int ce = c-1;
        int cnt = r*c;
        
        while(rs <= re and cs <= ce){
            for(int i = cs;i<=ce;i++){
                cnt--;
                ans.push_back(matrix[rs][i]);
            }
            rs++;
            for(int i = rs;i<=re;i++){
                cnt--;
                ans.push_back(matrix[i][ce]);
            }
            ce--;
            
            if(cnt == 0) break;
            
            for(int i = ce;i>=cs;i--){
                cnt--;
                ans.push_back(matrix[re][i]);
            }
            re--;
            for(int i = re;i>=rs;i--){
                cnt--;
                ans.push_back(matrix[i][cs]);
            }
            cs++;
            
            if(cnt == 0) break;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends