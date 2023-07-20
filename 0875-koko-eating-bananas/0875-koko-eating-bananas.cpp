class Solution {
public:
    
    
     int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1000000000;
        int ans= -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(canEatInTime(piles, mid, h)) ans = mid, right = mid - 1;
            else left = mid + 1;
        }
        return ans;
    }
    
    
    bool canEatInTime(vector<int>& piles, int k, int h){
        long long hours = 0;
        for(int pile : piles){
            long long div = pile / k;
            hours += div;
            if(pile % k != 0) hours++;
        }
        return hours <= h;
    }
};