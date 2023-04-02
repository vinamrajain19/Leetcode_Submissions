class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        
        vector<pair<int,int>> v;
        
        for(int i = 0;i<r1.size();i++){
            v.push_back({r1[i]-r2[i],i});
        }
        
        
        // diff-> neg -> take r2 else r1
        sort(v.rbegin(),v.rend());
        
        
        int sum = 0;
        
        int i =0;
        for(;i<k;i++){
            sum += r1[v[i].second];
        }
        
        for(;i<r2.size();i++){
            sum += r2[v[i].second];
        }
        
        return sum;
        
    }
};