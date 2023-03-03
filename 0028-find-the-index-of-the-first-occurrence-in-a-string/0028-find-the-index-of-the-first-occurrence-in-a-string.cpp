class Solution {
public:
    int strStr(string h, string n) {
        
        if(n.size() == 0) return 0;
        
        return h.find(n);
    }
};