class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.length();
        vector<int>res(n);
        int last_cost=0, sum=boxes[0]-'0';
        for(int i=1;i<n;i++){
            res[i]+=sum+last_cost;
            last_cost=res[i];
            sum+=(boxes[i]-'0');
        }
        
        last_cost=0,sum=boxes[n-1]-'0';
        
        for(int i=n-2;i>=0;i--){
            res[i]+=sum+last_cost;
            last_cost=(sum+last_cost);
            sum+=(boxes[i]-'0');
        }
        return res;
    }
};