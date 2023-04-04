class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> m;
        int ans = 1;
        for(int i = 0;i<s.size();i++){
            if(m.find(s[i]) == m.end()){
                m[s[i]] = 1;
            }
            else{
                ans++;
                m.clear();
                m[s[i]]++;
            }
        }
        return ans;
    }
};