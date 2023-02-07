class Solution {
public:
    
    // we have to collect fruits in serial order -> sliding window
    
    int totalFruit(vector<int>& fruits) {
        
        int i = 0;
        int j = 0;
        unordered_map<int,int> m;
        int ans = 0;
        
        while(j<fruits.size()){
            m[fruits[j]]++;
            
            if(m.size() <= 2){
                // window is the ans
                ans = max(ans,j-i+1);
                j++;
            }
            else if(m.size() > 2){
                while(m.size() > 2){
                    m[fruits[i]]--;
                    if(m[fruits[i]] == 0) m.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};