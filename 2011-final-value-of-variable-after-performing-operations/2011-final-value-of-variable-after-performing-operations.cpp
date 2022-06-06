class Solution {
public:
    int finalValueAfterOperations(vector<string>& o){
        int ans = 0;
        for(int i = 0;i<o.size();i++){
            if(o[i] == "++X" or o[i] == "X++") ans++;
            else ans--;
        }
        return ans;
    } 
};