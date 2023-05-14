
/* Intuition
derived array is given as

[a[0] ^ a[1],
 a[1] ^ a[2],
 a[2] ^ a[3],
 .
 .
 .
 a[n - 2] ^ a[n - 1]
 a[n - 1] ^ a[0]]
Take Bitwise-XOR of derived array.
Since x ^ x = 0 and x ^ 0 = x.
Use these properties to cancel out a[1], a[2], ..., a[n - 1].
We will be left with a[0] ^ a[0] = 0.

So Bitwise-XOR of derived array should be 0 for original to exist.

Proof of why this is a sufficient condition
If Bitwise-XOR comes 1 then it means there is some a[i] which didn't find it's another a[i] to cancel each other, meaning a[i] != a[i] which is a contradiction. So, for any possible original array, derived array's Bitwise-XOR will always be 0. If it is not, that means original does not exists.
    
*/

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans = 0;
        for(auto it : derived){
            ans = ans ^ it;
        }
        
        return ans == 0;
    }
};