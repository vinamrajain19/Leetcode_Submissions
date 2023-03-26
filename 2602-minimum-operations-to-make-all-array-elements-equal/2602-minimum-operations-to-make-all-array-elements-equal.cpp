class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        long long n=nums.size(), m=queries.size();

        vector<long long> ans;
        sort(nums.begin(), nums.end());

        vector<long long> prefix(n);
        for(int i=0;i<n;i++) prefix[i]=(long long)nums[i];
        for(int i=1;i<n;i++){
            prefix[i]+=prefix[i-1];
        }

        for(int i=0;i<queries.size();i++){
            long long value=queries[i];
            int index=-1;
            
            long long low=0, high=n-1;
            while(low<=high){
                long long mid=low+(high-low)/2;
                if(nums[mid]<=value){
                    index=mid;
                    low=mid+1;
                }
                else high=mid-1;          
            }
            if(index==-1){
                ans.push_back(prefix[n-1]-(value*n));
            }
            else{
                long long req1=(index+1)*value-prefix[index];
                long long req2=(prefix[n-1]-prefix[index])-(n-index-1)*value;
                ans.push_back(req1+req2);               
            }
        }
        return ans;        
    }
};