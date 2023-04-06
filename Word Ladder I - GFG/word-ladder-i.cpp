//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
 int ladderLength(string b, string e, vector<string>& w) {
        set<string> s(w.begin(),w.end());
        queue<pair<string,int>> q;
        q.push({b,0});
        
        while(q.size()){
            
            string t = q.front().first;
            int steps = q.front().second;
            
            q.pop();
            
            if(t == e) return steps+1;
            
            for(int i = 0;i<t.size();i++){
                char x = t[i];
                
                for(char ch = 'a';ch<='z';ch++){
                    t[i] = ch;
                    if(s.find(t) != s.end()){
                        s.erase(t);
                        q.push({t,steps+1});
                    }
                }
                t[i] = x;
            }
        }
        
        return 0;
    }
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        return ladderLength(startWord,targetWord,wordList);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends