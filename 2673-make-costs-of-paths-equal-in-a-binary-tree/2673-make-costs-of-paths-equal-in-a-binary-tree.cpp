class Solution {
public:
    
    // using height concept
    
    int ans = 0;
    int f(int n,vector<int> &cost,int i){
        if(i > n) return 0;
        
        int l = f(n,cost,2*i);
        int r = f(n,cost,2*i+1);
        
        ans += abs(l-r);
        
        return cost[i-1] + max(l,r);
    }
    
    
    int minIncrements(int n, vector<int>& cost) {
        f(n,cost,1);
        return ans;
    }
};