class Solution {
public:
    
    bool f(string &t,string &it){
        int i = 0;
        int j = 0;
        int cnt = 0;
        while(i < 8){
            if(t[i] != it[j]){
                cnt++;
            }
            i++,j++;
        }
        
        return cnt <= 1;
    }
    
    int minMutation(string s, string e, vector<string>& bank) {
        queue<string> q;
        q.push(s);
        int ans = 0;
        vector<int> vis(bank.size(),0);
        
        while(q.size()){
            int n = q.size();
            while(n--){
                string t = q.front();
                q.pop();
                if(t == e) return ans;
                for(int i = 0;i<bank.size();i++){
                    string it = bank[i];
                    if(f(t,it) and vis[i] == 0) q.push(it),vis[i] = 1;
                }
                
            }
            ans++;
        }
        
        return -1;
    }
};