class Solution {
public:
    int n,dp[62][(1<<16)+2];
    vector<int> v,cur,ans;
    unordered_map<string,int> mp;
    
    void sol(int id,int mask)
    {
        if(mask==(1<<n)-1)
        {
            if((int)cur.size()<(int)ans.size() || (int)ans.size()==0)
                ans=cur;
            return ;
        }
        
        if(id==n || ((int)cur.size()>(int)ans.size() && ans.size()>0)) return ;
        
        if(mask & (1<<id)) sol(id+1,mask);
        else
        {
            for(int i=0;i<(int)v.size();i++)
                if(v[i] & (1<<id))
                {
                    cur.push_back(i);
                    sol(id+1,mask|v[i]);
                    cur.pop_back();
                }
        }
    }
    
    vector<int> smallestSufficientTeam(vector<string>& sk, vector<vector<string>>& peo) 
    {
        n=sk.size();
        for(int i=0;i<n;i++)
            mp[sk[i]]=i;
        for(int i=0;i<peo.size();i++)
        {
            int mask=0;
            for(int j=0;j<peo[i].size();j++)
                mask|=(1<<mp[peo[i][j]]);
            v.push_back(mask);   
        }
        
        sol(0,0);
        return ans;         
    }
};