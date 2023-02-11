//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        vector<int> v(26,-1);
        
        for(int i = 0;i<a.size();i++){
            if(v[a[i] - 'a'] == -1){
                v[a[i] - 'a'] = i;
            }
        }
        
        int fi = -1;
        int se = -1;
        
        for(int i = 0;i<a.size();i++){
            // check for smaller elements than a[i]
            
            bool f = false;
            for(int j = 0;j<a[i]-'a';j++){
                
                // this should lie after ith char
                if(v[j] > v[a[i]-'a']){
                    fi = i;
                    se = j;
                    f = true;
                    break;
                }
            }
            
            if(f) break;
        }
        
        if(fi < a.size()-1){
            char x = a[fi];
            char y = (char)se+'a';
            
            for(int i = 0;i<a.size();i++){
                if(a[i] == x){
                    a[i] = y;
                }
                else if(a[i] == y){
                    a[i] = x;
                }
            }
        }
        
        return a;
        
    }
    
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends