class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m; // tostore last index of every char
        for(int i = 0;i<s.size();i++){
            m[s[i]] = i;
        }
        
        // using set to store char until we found last index
        // partition -> when st . size () == track -> track -> i == lastindex of char
        
        vector<int> ans;
        unordered_set<char> st;
        int track = 0;
        int cnt = 0;
        for(int i = 0;i<s.size();i++){
            cnt++;
            st.insert(s[i]);
            
            if(i == m[s[i]]){
                track++;
            }
            
            if(track == st.size()){
                ans.push_back(cnt);
                cnt = 0;
                track = 0;
                st.clear();
            }
        }
        return ans;
    }
};