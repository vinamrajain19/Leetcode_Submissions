class Solution {
public:
     //min heap -> take small one and check for neighbour if negihbour is > than increse candy
    int candy(vector<int>& r) {
        int n = r.size();
        vector<int> v(n,1);
        
      priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
        
        for(int i = 0;i<n;i++){
          q.push({r[i],i});
        }
        while(q.size()!= 0){
            int val = q.top().first;
            int idx = q.top().second;
            q.pop();
            
            if(idx - 1 >= 0 and r[idx-1] > r[idx]){
                v[idx-1] = max(v[idx-1],1 + v[idx]);
            }
            
            if(idx + 1 < n and r[idx+1] > r[idx]){
                v[idx+1] = max(v[idx+1],1 + v[idx]);
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++) ans += v[i];
        return ans;
    }
};