class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i=0,j=0;
        while(m!=0&&i<m&&n!=0&&j<n)
        {
            if(nums1[i]<=nums2[j])
                ans.push_back(nums1[i++]);
            else
                ans.push_back(nums2[j++]);
        }
        while(m!=0&&i<m)
        {
            ans.push_back(nums1[i++]);
        }
        while(n!=0&&j<n)
        {
            ans.push_back(nums2[j++]);
        }
        nums1=ans;
    }
};