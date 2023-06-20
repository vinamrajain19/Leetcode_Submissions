class Solution {
public:
    void f(vector<int>& c, int k,int i,vector<int> &eat,int &ans){
        if(i == c.size()){
            int temp = *max_element(eat.begin(), eat.end());
            ans = min(ans,temp);
            return;
        }
        
        for(int j = 0;j<k;j++){
            eat[j] += c[i];
            f(c,k,i+1,eat,ans);
            eat[j] -= c[i];
        }
    }
    
    int distributeCookies(vector<int>& c, int k) {
        vector<int> eat(k,0);
        int ans = 1e9;
        f(c,k,0,eat,ans);
        return ans;
    }
};