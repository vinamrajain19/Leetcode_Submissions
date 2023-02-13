class Solution {
public:
    int countOdds(int low, int high) {
        int d = (high-low);
        
        if(low % 2 == 1 and high % 2 == 1){
             return (d/2) - 1 + 2;
        }
        else if(low % 2 == 0 and high % 2 == 0){
            return (d/2);
        }
        else{
            return floor(d/2) + 1;
        }
    }
};