class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        
        int ans = 0;
        for(auto it : s){
            if(it == '(') st.push(it);
            else if(st.size() != 0 and it == ')') st.pop();
            else if(st.size() == 0 and it == ')') ans++;
        }
        
        while(st.size() > 0){
            ans++;
            st.pop();
        }
        
        return ans;
    }
};