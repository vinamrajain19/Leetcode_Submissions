class Solution {
public:
    
    // Create a vector of 26 unordered_sets, each unordered_set will store strings starting with the same character.
// Iterate over each string in the input vector 'ideas'.
// Insert each string into the unordered_set corresponding to its first character.
// Calculate the number of distinct names by iterating over the unordered_sets twice (once for each pair of sets), comparing the size of the sets before and after adding elements from both sets.
// Return the result.
    
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        
        vector<unordered_set<string>> v(26);
        
        for(auto it : ideas) v[it[0]-'a'].insert(it.substr(1));
        
        for(int i = 0;i<26;i++){
            for(int j = i+1;j<26;j++){
                
                unordered_set<string> s;
                
                s.insert(v[i].begin(),v[i].end());
                s.insert(v[j].begin(),v[j].end());
                
                ans += ((long long)v[i].size() - s.size()) * ((long long)v[j].size()-s.size());
            }
        }
        
        return ans*2;
    }
};