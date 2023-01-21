class Solution {
public:
    
    
    
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n=nums1.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)
        {
            v[i]={nums2[i],nums1[i]};
        }
        
        //sort in descending order ot get min efficiency for every i we traverse
        sort(rbegin(v),rend(v));
        
        //priority queue to get the smallest sum 
        priority_queue<int,vector<int>,greater<int>> pq; 
        long long sum=0;
        long long ans=0;
        for(auto [e,speed] : v)
        {
            sum += speed;
            
			//push the current speed to the pq
            pq.push(speed);
            if(pq.size()>k)
            {
                //remove the smallest speed
                sum-=pq.top();
                pq.pop();
            }
            
			//since e is the currents small efficiency 
            if(pq.size() ==k) ans=max(ans,sum*e);
        }
        return ans;
    }
};