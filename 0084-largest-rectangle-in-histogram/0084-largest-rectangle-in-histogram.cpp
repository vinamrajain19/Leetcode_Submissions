class Solution {
public:
    
    int largestRectangleArea(vector<int>& a) {
        if(a.size() == 1){
            return a[0];
        }
        
        vector<int> left;
        vector<int> right;
        
        stack<pair<int,int>> s;
        for(int i = 0;i<a.size();i++){
            if(s.size() == 0) {
                left.push_back(-1);
            }
            else if(s.size() > 0 and s.top().first < a[i]){
                left.push_back(s.top().second);
            }
            else if(s.size() > 0 and s.top().first >= a[i]){
                while(s.size() > 0 and s.top().first >= a[i]){
                    s.pop();
                }
                if(s.size() == 0) {
                    left.push_back(-1);
                }
                else{
                    left.push_back(s.top().second);
                }
            }
            
            s.push({a[i],i});
        }
        
        while(!s.empty()){
            s.pop();
        }
        
        for(int i = a.size() -1 ;i >=0 ;i--){
            if(s.size() == 0) right.push_back(a.size());
            else if(s.size() > 0 and s.top().first < a[i]){
                right.push_back(s.top().second);
            }
            else if(s.size() > 0 and s.top().first >= a[i]){
                while(s.size() > 0 and s.top().first >= a[i]){
                    s.pop();
                }
                
                if(s.size() == 0){
                    right.push_back(a.size());
                }
                else{
                    right.push_back(s.top().second);
                }
            }
            s.push({a[i],i});
        }
        
        
        reverse(right.begin(),right.end());
   
        
        int area = 0;
        for(int i=0;i<a.size();i++){
            area=max(area, a[i]*(right[i]-left[i]-1));
        }
        
        
        return area;
    }
};