
/* Sort the numbers in increasing order.

n = 1, nums = [a],
ans = [$$a^3$$]
n = 2, nums = [a, b],
ans = [$$a^3 + b^3 + b^2.a$$]
n = 3, nums = [a, b, c],
ans = [$$a^3 + b^3 + c^3 + c^2.(b + 2a) + b^2.a$$]
n = 4, nums = [a, b, c, d],
ans = [$$a^3 + b^3 + c^3 + d^3
+d^2.(c + 2b + 4a) + c^2.(b + 2a) + b^2.a$$]
Do you see a pattern? :

*/

class Solution {
public:
    const int kMod = 1e9+7;
    
    long long pw(long long a, long p) {
        long long r = 1;
        while (p--)
            r = (r * a)%kMod;
        return r;
    }
    
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        
        long long prev = 0;
        long long ans = 0;
        
        
        for (int num : nums) {
            ans = (ans + (long long)pw(num, 3))%kMod;
            
            ans = (ans + ((long long)pw(num, 2)* prev)%kMod)%kMod;
            
            prev = (prev*2 + num)%kMod;
        }
        
        return ans;
    }
};