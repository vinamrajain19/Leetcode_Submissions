class Solution {
public:
    int c(string s){
        int ans = 0;
        for(int  i= 0;i<s.size();i++){
            if(s[i] == ' ') ans++;
        }
        return ans+1;
    }
    
    string largestWordCount(vector<string>& ms, vector<string>& s) {
        map<string,int> m;
        int n = s.size();
        for(int  i = 0;i<n;i++){
           m[s[i]]  += c(ms[i]); 
        }
        
        pair<string,int> p("",INT_MIN);
        for(auto it : m){
            if(it.second >= p.second){
                p.second = it.second;
                p.first = it.first;
            }
            
        }
        return p.first;
    }
};