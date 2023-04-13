class Solution {
public:
    bool validateStackSequences(vector<int>& p, vector<int>& popp) {
        stack<int> s;
        int j = 0;
        for(int i  = 0;i<p.size();i++){
            s.push(p[i]);
            while(s.size() and popp[j] == s.top()){
                j++;
                s.pop();
            }
        }
        
        return s.size() == 0;
    }
};