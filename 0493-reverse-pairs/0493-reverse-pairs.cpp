class Solution {
public:
    
    
    long long int ans = 0;
    
    void merge(vector<int> &nums,long long N,long long low,long long mid,long long high){
        
        
        int i=low;
        int j=mid+1;
        
        vector<int>temp(high-low+1);
        
        while(i<=mid and j<=high)
        {
            if(nums[i]>2*1ll*nums[j])
            {
                ans+=(mid-i+1);
                j++;
            }
            else
            {
                i++;
            }
        }
        
        i=low;
        j=mid+1;
        int k=0;
        
        while(i<=mid and j<=high)
        {
            if(nums[i]<nums[j])
            {
                temp[k++]=nums[i++];
            }
            else
            {
                temp[k++]=nums[j++];
            }
        }
        
        while(i<=mid)
            temp[k++]=nums[i++];
        while(j<=high)
            temp[k++]=nums[j++];
        
        for(i=low;i<=high;i++)
            nums[i]=temp[i-low];
        return;
    }
    
    void mergesort(vector<int> &arr,long long N,long long s,long long e){
        if(s >= e) return;
        
        
        long long m = (s+e)/2;
        mergesort(arr,N,s,m);
        mergesort(arr,N,m+1,e);
        merge(arr,N,s,m,e);
    }
    
    
    int reversePairs(vector<int>& nums) {
        mergesort(nums,nums.size(),0,nums.size()-1);
        return (int)ans;
    }
};