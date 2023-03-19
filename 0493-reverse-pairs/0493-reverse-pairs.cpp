class Solution {
public:
    
    
    long long int ans = 0;
    
    void merge(vector<int> &arr,long long N,long long s,long long m,long long e){
        
        
        long long i = s;
        long long j = m+1;
        long long k = 0;

        //long long temp[e-s+1];
        
        while(i <= m and j <= e){
            if((long long)arr[i] > (long long)2*arr[j]){
                ans += m-i+1;
                j++;
                //temp[k++] = arr[j++];
            }
            else{
                //temp[k++] = arr[i++];
                i++;
            }
        }
        
        sort(arr.begin() + s,arr.begin() + e +1);
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