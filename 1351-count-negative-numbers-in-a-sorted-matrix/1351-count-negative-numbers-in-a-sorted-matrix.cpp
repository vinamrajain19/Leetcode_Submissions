class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int negind = grid[0].size()-1;
        
        for(auto it : grid){
            
            while(negind >= 0 and it[negind] < 0){
                negind--;
            }
            
            ans += grid[0].size() - negind - 1;
        }
        return ans;
    }
};