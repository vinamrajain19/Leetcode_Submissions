
 /*  case 1: nums = [1], nums only has one value, so directly return true.

case 2: nums = [2, 3, 6, 1], nums contains "1", gcd(x, 1) always is "1", so directly return false.

case 3: nums = [2, 3, 6],
in this case, if we want to jump from "2" -> "3", we need to find another value,
which factors contains "2", "3".

case 4: nums = [2, 4, 3, 9] because "2" can not jump to "3" "9", so return false.

based on above observation.
we can translate this problem into factor group.
if the value which the factors is f1, f2, f3, we can use union_find to union these factors.
finally, we need check how many factor group exist in nums.
if factor group = 1, return true
if factor group > 1, return false

for example:

case 3:
nums = [2, 3, 6],
factors = [(2), (3), (2,3)], factor group is 1

case 4:
nums = [2, 4, 3, 9],
factors = [(2), (2), (3), (3)], factor group is 2

Complexity
Time complexity: O(n * sqrt(x)), x is maximum value in nums.
Space complexity: O(n)
    */
    
class union_find {
public:
    vector<int> p;
    vector<int> r;
    union_find(int n) {
        p.resize(n, 0);
        r.resize(n, 0);
        
        for(int i = 0 ; i < n ; i++) {
            p[i] = i;
        }
    }
    
    int Find(int x) {
        if(p[x] != x) {
            p[x] = Find(p[x]);
        }
        return p[x];
    }
    
    void Union(int x, int y) {
        int px = Find(x);
        int py = Find(y);
        if(px == py) {
            return;
        }
        
        if(r[px] > r[py]) {
            p[py] = px;
        }
        else if(r[py] > r[px]) {
            p[px] = py;
        }
        else {
            p[py] = px;
            r[px]++;
        }
    }
    
};
class Solution {
public:
    
    void find_factors(int val, vector<int> &v) {
        for(int j = 2 ; (j * j) <= val ; j++) {
            bool add = false;
            while((val % j) == 0) {
                val = val / j;
                add = true;
            }
            if(add) {
                v.push_back(j);
            }
        }

        if(val > 1) {
            v.push_back(val);
        }
    }
    
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v(n);
        union_find uf(100000);
        unordered_set<int> st;
        
        if(n == 1) {
            return true;
        }
        
        //check failed case 
        for(int i = 0 ; i < n; i++) {
            if(nums[i] == 1) {
                return false;
            }
            find_factors(nums[i], v[i]);
        }
        for(int i = 0 ; i < n ; i++) {
            for(int j = 1 ; j < v[i].size(); j++) {
                uf.Union(v[i][0], v[i][j]);
            }
        }
        
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < v[i].size(); j++) {
                st.insert(uf.Find(v[i][j]));
            }
        }
        
        
        return st.size() == 1;
    }
};