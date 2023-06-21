class Solution {
public:
    long long taskSchedulerII(vector<int>& t, int s) {
       unordered_map<int,long long> m;
       // for(auto it : t) m[it]++;
        
        long long ans = 0;
        
        for(int i = 0;i<t.size();i++){
            if(m.find(t[i]) == m.end()){
                ans++;
                m[t[i]] = ans;
            }else{
                if(ans - m[t[i]] < s){
                    ans += (s - (ans - m[t[i]])) + 1;
                    m[t[i]] = ans;
                }
                else{
                    ans++;
                    m[t[i]] = ans;
                }
            }
        }
        return ans;
    }
};