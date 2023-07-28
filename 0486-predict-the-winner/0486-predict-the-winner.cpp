class Solution {
public:
    
    
    int dp[21][21]={};
    
    int takeStone(bool Player, int l, int h, vector<int>& piles)
    {
        // base cases : impossible and so return -1 as scores are non-negative
        if(l>h) return -1;
        
        // l==h return the score
        if(l==h) return piles[l];
        
        // return precalculated result
        if(dp[l][h]!=-1) return dp[l][h];
        
      
        if(Player)    
            dp[l][h] = max(piles[l]+takeStone(!Player,l+1,h,piles),piles[h]+takeStone(!Player,l,h-1,piles));
        
        
        else
            dp[l][h] = min(takeStone(!Player,l+1,h,piles),takeStone(!Player,l,h-1,piles));

        return dp[l][h];
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        
        // Player1 turn = true, Player2 turn = false
        // Game result = max score of Player1 - max score of Player2
        // If result >= 0 then Player1 wins
			int p1 = takeStone(true,0,n-1,nums);
            int p2 =accumulate(nums.begin(),nums.end(),0)-p1;
         return p1 >= p2;// Incase of draw Player1 wins
    }
};