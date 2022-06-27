// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    
	public:



     void permutation(set<string> &st, string S, int i)
    {
        if(i==(int)S.size()){
            st.insert(S);
        }
        for(int j=i; j<(int)S.size(); j++){
            swap(S[i],S[j]);
            permutation(st,S,i+1);
            swap(S[i],S[j]);
        }
        
    }
		vector<string>find_permutation(string S)
		{
		   set<string> st;
         vector<string>v;
        permutation(st,S,0);
        for(auto it:st)
        v.push_back(it);
        return v;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends