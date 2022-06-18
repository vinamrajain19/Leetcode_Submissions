class Solution {
public:
    int minDeletions(string s) {
        // there is no add or remove thing that why use greddy
        unordered_map<char,int> m;
        for(int i = 0;i<s.size();i++) m[s[i]]++;
        
        unordered_set<int> st;
        int ans = 0;
        for(auto it : m){
            if(st.find(it.second) == st.end()){
               st.insert(it.second);
            }
            else{
                while(st.find(it.second) != st.end()){
                    it.second--;
                    ans++;
                }
                if(it.second > 0) st.insert(it.second);
            }
        }
        return ans;
    }
};