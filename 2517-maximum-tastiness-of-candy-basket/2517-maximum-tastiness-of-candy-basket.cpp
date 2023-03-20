class Solution {
public:
    
    // same as aggressive cows

    bool f(vector<int> &price,int k,int t){
        int c = 1;
        int last = price[0];
        for(int i = 1;i<price.size();i++){
            if(price[i] - last >= t){
                c++;
                last = price[i];
            }
            if(c == k) return true;
        }
        return false;
    }
    
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int n = price.size();
        int s = 0;
        int e = price[n-1] - price[0];
        
        int ans =0;
        while(s <= e){
            int m = (s+e)/2;
            
            if(f(price,k,m)){
                ans = m;
                s = m+1;
            }
            else e  = m-1;
        }
        return ans;
    }
};