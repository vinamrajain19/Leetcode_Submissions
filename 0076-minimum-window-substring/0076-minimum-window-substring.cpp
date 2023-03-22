class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        
        for(auto it : t) m[it]++;
        
        int i = 0;
        int j = 0;
        int ans = 1e9;
        string x;
        
        int cnt = m.size();
        
        int st = -1;
        
        while(j < s.size()){
            
            if(m.find(s[j]) != m.end()){
                m[s[j]]--;
                if(m[s[j]] == 0){
                    cnt--;
                }
            }
            
            
            
            if(cnt > 0) j++;
            
            else if(cnt == 0){
                
                
                while(cnt == 0 and i < s.size()){
                    
                    if(j-i+1 < ans){
                        st = i;
                        ans = j-i+1;
                       // x = s.substr(i,ans);
                    }
                    
                    if(m.find(s[i]) != m.end()){
                        m[s[i]]++;
                        if(m[s[i]] == 1) cnt++;
                    }
                    
                    i++;
                }
                
                j++;
                
                
            }
        }
        
        if(st == -1) return "";
        return s.substr(st,ans);
    }
};