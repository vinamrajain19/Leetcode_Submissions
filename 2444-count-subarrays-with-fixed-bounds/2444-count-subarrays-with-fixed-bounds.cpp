class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int  n = nums.size();
        long long cnt = 0, mini = -1, maxi = -1; 
        int i = 0, j = 0;                        //for iterating nums

        while(j < n)                             //can also use for loop for j
        {
            if(nums[j] < minK || nums[j] > maxK) //subarray of no use now, move window
            {
                mini = maxi = -1;                //set new mini and maxi of new window
                i = j+1;                         //slide the window
            }

            if (nums[j] == minK) mini = j;       //update the index of recently observed minK
			if (nums[j] == maxK) maxi = j;       //update the index of recently observed maxK

            cnt += max(0LL, min(mini, maxi) - i + 1);  //if 2nd part of max is -ve means we don't have minK and maxK in window now so max(0, -ve) = 0, no increment

            j++;                                 //keep increasing the window towards right
        }
		return cnt;
    }
};