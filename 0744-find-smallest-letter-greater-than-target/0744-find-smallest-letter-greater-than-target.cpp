class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = '.';
        
        int s = 0;
        int e = letters.size()-1;
        
        while(s <= e){
            int m = (s+e)/2;
            
            if(letters[m] <= target){
                s = m+1;
            }
            else{
                ans = letters[m];
                e = m-1;
            }
        }
        
        if(ans == '.') return letters[0];
        return ans;
    }
};