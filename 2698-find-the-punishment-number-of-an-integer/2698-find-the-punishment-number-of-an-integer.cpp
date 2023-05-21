class Solution {
public:
    bool f(string& s, int startIdx, int target)
    {
        if (startIdx == s.size() && target == 0) return true;
        if (target < 0) return false;
        
        bool ans = false;
        int leftNum = 0;
      
        for (int i = startIdx; i < s.size(); i++) //try all possible pivot points
        {
            leftNum = (leftNum * 10) + (s[i] - '0'); //keep the left
            
            bool isPossible = f(s, i + 1, target - leftNum); //recurse for right
            
            if (isPossible) { ans = true; break; }
        }
       
        return ans;
    }
    
    int punishmentNumber(int n)
    {
        int sum = 0;
        for (int num  = 1; num <= n; num++)
        {
            int sqr = num * num;
            string s = to_string(sqr);
            if (f(s, 0, num)) 
            {
                sum += sqr;
            }
        }
        return sum;
    }
};