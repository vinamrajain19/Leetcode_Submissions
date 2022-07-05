class Solution {
public:
   
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        int m = rolls.size();

        for(int i = 0;i<rolls.size();i++){
            sum += rolls[i];
        }
        
        int x = (n+m) * mean - sum;
        if(6 * n < x or x < 1 or x < n) return {};
        
        vector<int> ans;
        while(x){
            int t = x/n;
            x = x - t;
            ans.push_back(t);
            n--;
        }
        
        return ans;
        
    }
};