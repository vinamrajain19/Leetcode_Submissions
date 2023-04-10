class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for(int  i =0;i<s.size();i++){
            
            if(s[i] == '(' or s[i] == '{' or s[i] == '[') st.push(s[i]);
            
            else if(s[i] == ')'){
               if(st.size() == 0) return false;
               else if(st.top() == '(') st.pop();
               else return false;
            }
            
            else if(s[i] == '}'){
                if(st.size() == 0) return false;
                else if(st.top() == '{') st.pop();
                else return false;
            }
            
            else if(s[i] == ']'){
                if(st.size() == 0) return false;
                else if(st.top() == '[') st.pop();
                else return false;
            }
            
        }
        if(st.size() == 0) return true;
        return false;
    }
};