class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        
        vector<pair<int,int>> vp;
        for(int i=0;i<queries.size();i++){
            vp.push_back({queries[i],i});
        }
        sort(vp.begin(),vp.end());
        
        vector<int> ans(queries.size());
        
        vector<vector<int>> vis(m , vector<int> (n,0));
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        
        pq.push({grid[0][0],0,0}); vis[0][0] = 1;
        
        int cnt = 0;
        
        for(auto [val,idx] : vp){            
            while(pq.size()){
                auto [v,i,j] = pq.top();
                
                if(v >= val) break;
                else pq.pop(), cnt++;
                
                if(i-1 >= 0 and !vis[i-1][j]) pq.push({grid[i-1][j],i-1,j}), vis[i-1][j] = 1;
                if(j-1 >= 0 and !vis[i][j-1]) pq.push({grid[i][j-1],i,j-1}), vis[i][j-1] = 1;
                if(i+1 <  m and !vis[i+1][j]) pq.push({grid[i+1][j],i+1,j}), vis[i+1][j] = 1;
                if(j+1 <  n and !vis[i][j+1]) pq.push({grid[i][j+1],i,j+1}), vis[i][j+1] = 1;
            }   
            ans[idx] = cnt;
        }
        
        return ans;
    }
};
