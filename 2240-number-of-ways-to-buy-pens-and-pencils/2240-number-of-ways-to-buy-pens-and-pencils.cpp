class Solution {
public:
   /* long long help(int total,int cost1,int cost2,vector<int> &v,int i){
        
        if(total == 0) return 0;
        if(i == 0) return total/v[i];
        
        long long no = help(total,cost1,cost2,v,i-1);
        
        long long take = 0;
        
        if(v[i] <= total) take = 1 + help(total - v[i],cost1,cost2,v,i);
        
        return no + take;
    } */
    
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        
        vector<int> v;
        v.push_back(cost1);
        v.push_back(cost2);
        
        int m = v.size();
        int n = total;
        
        vector<long long> prev(n+1,0),temp(n+1,0);
        
        for(int i = 0;i < m;i++) prev[0] = 0;
        
        for(int T = 1; T < n+1;T++) prev[T] = T/v[0];
        
        for(int i = 1; i< m; i++){
            for(int T = 1; T < n+1;T++){
                long long nottake = prev[T];
        
                long long take = 0;
                
                if(T >= v[i]) take = 1 + temp[T - v[i]];

                temp[T] =  take + nottake;
            }
            prev = temp;
        }
        
        return prev[n] + 1;

    }
};