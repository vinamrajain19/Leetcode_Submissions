class Solution {
public:
    
    vector<int> ans;
    
    void f(int n,int k,int idx,int no){
        if(idx == n){
            ans.push_back(no);
            return;
        }
        
        for(int i = 0;i<10;i++){
            if(i==0 and idx == 0) continue;
            if(idx == 0){
                no += i;
                f(n,k,idx+1,no);
                no -= i; // backtrack
            }
            else{
                int m = no%10;
                if(abs(i-m) == k){
                 int t = no;
                 no = no * 10 + i;
                 f(n,k,idx+1,no);
                 no = t;
                }
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        f(n,k,0,0);
        return ans;
    }
};