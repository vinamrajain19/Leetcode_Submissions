class Solution {
public:
    vector<string> removeAnagrams(vector<string>& w) {
        vector<string> ans;
        ans.push_back(w[0]);
        string t = w[0];
        sort(t.begin(),t.end());
        for(int i = 1;i<w.size();i++){
            string x = w[i];
            sort(x.begin(),x.end());
            if(x==t){
                continue;
            }
            else{
                ans.push_back(w[i]);
                t = x;
            }
        }
        return ans;
    }
};