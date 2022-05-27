class Solution {
public:
    int countOperations(int n1, int n2) {
        int ans = 0;
        while(n1 != 0 and n2 != 0){
            if(n1 > n2){
                n1 -= n2;
                ans++;
            }
            else{
                n2 -= n1;
                ans++;
            }
        }
        return ans;
    }
};