class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();  
        sort(nums.begin() , nums.end());  // sort the array to use the two pointers method
        vector<vector<int>> ans;  
        set<vector<int>> s;   // to store and remove the duplicate answers
		
        for(int i = 0 ; i < n; i++){
              //  if ((i>0) && (nums[i]==nums[i-1]))
                //     continue
                int x = i+1 , y = n-1;
                
                while(x < y){
				
                    int sum = nums[i] + nums[x] + nums[y];
                    
                    if(sum > 0) y--;
                    else if(sum < 0 ) x++;
                    else  {
                        s.insert({nums[i] , nums[x] , nums[y]});
                        x++;
                        y--;
                    }
                }
        }
		
        for(auto i : s){
            ans.push_back(i);  // store the answers in an array(ans)
        }
		
        return ans;
    }
};