class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n,'a');
        
        k = k - n;
        
        while(k){
            if(k>25){
                ans[n-1] = ans[n-1] + 25;
                k -= 25;
            }else{
                ans[n-1] = ans[n-1] + k;
                k-=k;
            } 
            
            n--;
        }
        return ans;
    }
};