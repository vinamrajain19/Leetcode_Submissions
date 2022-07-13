class Solution {
public:
    vector<string> ans;
    void f(int n,int i,int j,string temp){
        if(i == n and j == n){
            ans.push_back(temp);
            return;
        }
        
        if(i<n){
            temp += '(';
            f(n,i+1,j,temp);
            temp.pop_back();
        }
        
        if(j<i){
            temp += ')';
            f(n,i,j+1,temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        f(n,0,0,"");
        return ans;
    }
};