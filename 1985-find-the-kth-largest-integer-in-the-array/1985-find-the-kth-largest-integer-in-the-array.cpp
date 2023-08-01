class Solution {
public:
    struct comp
    {
        bool operator()(const string &a, const string &b)
        {
            return a.length()==b.length() ? (a>b) : a.length()>b.length();
        }    
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        priority_queue<string,vector<string>,comp>pQ;
        
        for(auto &t : nums)
        {
            pQ.push(t);
            
            if(pQ.size()>k)pQ.pop();
        }
        
        return pQ.top();
    }
};