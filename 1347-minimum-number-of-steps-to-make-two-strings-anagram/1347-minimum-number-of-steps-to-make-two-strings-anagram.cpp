class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> m;
        for(auto it : s){
            m[it]++;
        }
        int ans = 0;
        for(int i = 0;i<t.size();i++){
            if(m.find(t[i]) == m.end()){
                ans++;
            }
            else if((m.find(t[i]) != m.end())){
                m[t[i]]--;
                if(m[t[i]] == 0) m.erase(t[i]);
            }
        }
        return ans;
                    
    }
};