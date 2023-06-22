class Solution {
public:
    vector<vector<string>> ans;
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> m;
        
        for(auto i : strs){
            string x = i;
            sort(x.begin(),x.end());
            m[x].push_back(i);
        }
        
        for(auto it : m){
            ans.push_back(it.second);
        }
        
        return ans;
        
    }
};