class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        long long sum = 0;
        for(auto it : card) sum += it;
        
        int i = 0;
        int j = 0;
        long long mn = 1e9;
        long long x = 0;
        
        if(k == n) return sum;
        
        while(j < card.size()){
            x += (long long)card[j];
            
            if(j-i+1 < n - k){
                j++;
            }
            else if(j-i+1 == n-k){
                mn = min(mn,x);
                //cout<<mn<<" ";
                x -= (long long)card[i++];
                j++;
            }
        }
        
        long long t = sum - mn;
        return t;
    }
};