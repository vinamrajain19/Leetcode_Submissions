class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m+n,0);
        
        int i = 0;
        int j = 0;
        int k = 0;
        
        while(i < m and  j <n){
            if(nums1[i] < nums2[j]){
                ans[k++] = nums1[i++];
            }
            else{
                ans[k++] = nums2[j++];
            }
        }
        
        while(i<m){
            ans[k++] = nums1[i++];
        }
        while(j<n){
            ans[k++] = nums2[j++];
        }
        nums1 = ans;
    }
};