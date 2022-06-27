// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
       int ans = 0;
       int c = 0;
       int o = 0;
       for(int i = 0;i<str.size();i++){
           if(str[i] == '0') c++;
           if(str[i] == '1') o++;
           
           if(o == c){
               ans++;
               o = 0;
               c = 0;
           }
           
       }
       if(o == c) return ans;
       return -1;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends