//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int c[], int N, int K)
    {
        int x[N];
        for(int i = 0;i<N;i++) x[i] = c[i];
        sort(c,c+N);
        
        int i = 0;
        int j = N-1;
        
        int mn = 0;
        
        while(i <= j){
            mn += c[i];
            j -= K;
            i++;
        }
        
        sort(x,x+N,greater<int>());
        i = 0;
        j = N-1;
        
        int mx = 0;
        
        while(i <= j){
            mx += x[i];
            j -= K;
            i++;
        }
        
        return {mn,mx};
        // Write Your Code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends