class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long suc) {
        vector<int> ans;
        
        sort(p.begin(),p.end());
        
        for(int i = 0;i<s.size();i++){
            int x = 0;
            int y = p.size()-1;
            
            //int t = 0;
            while(x <= y){
                int m = (x+y)/2;
                
                if((long long)s[i] * (long long)p[m] >= suc){
                    y = m-1;
                }
                else x = m+1;
            }
            
            if(x == p.size()) ans.push_back(0);
            else ans.push_back(p.size()-x);
            
        }
        
         //cout<<endl;
        return ans;
       
        
    }
};