class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0; 
        //Xoring all elements
        for(int i=0;i<nums.size();i++){
            x^=nums[i];
        }
        //index for bit difference
        int idx;
		
        //Find the bit at which two numbers differ
        for(int i=0;i<32;i++){
            if(x&(1<<i)){
                idx=i;break;
            }
        }
        //Finding the 1st number
        int first=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&(1<<idx)){
                first^=nums[i];
            }
        }
		//second number will be xor of complete and first
        int second=first^x;
        return {first,second};
    }
};