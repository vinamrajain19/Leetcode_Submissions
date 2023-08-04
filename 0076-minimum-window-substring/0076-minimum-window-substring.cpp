class Solution {
public:
    string minWindow(string s, string t) {
        if(s == t) return s;
        
        int i = 0;
        int j = 0;
        
        unordered_map<char,int> m;
        
        for(auto it : t) m[it]++;
        
       
        
        int len = 1e9;
        
        int start  = -1;
        int cnt = m.size();
        
        while(j < s.size()){
            
            
            if(m.find(s[j]) != m.end()){
                m[s[j]]--;
                if(m[s[j]] == 0) cnt--;
            }
            
            
            
            while(cnt == 0){
                
                if(len > j-i+1){
                    len = j-i+1;
                    start = i;
                }
                
                if(m.find(s[i]) != m.end()){
                    m[s[i]]++;
                    if(m[s[i]] == 1) cnt++;
                }
                
                i++;
            }
            
            j++;
        }
        
        cout<<start;
        
        if(len == 1e9 or start == -1) return "";
        
        return s.substr(start,len);
        
        
    }
};