class Solution {
public:
     int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> v;
        //copy 1st row as it is
        for(int j = 0;j<matrix[0].size();j++){
            v.push_back(matrix[0][j] - '0');
        }
        
        int ans = MAH(v);
        
        //now for other rows check if there is zero then make whole value zero else add it in existing vector
        for(int i = 1;i<matrix.size();i++){   // row
            for(int j = 0;j<matrix[i].size();j++){
                if(matrix[i][j] == '0'){
                    v[j] = 0;
                }
                else{
                    v[j] = v[j] + 1;
                }
            }
            
            ans = max(ans,MAH(v));
        }

        cout<<endl;
        for(int i = 0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        
        return ans;
    }
    
    int MAH(vector<int> a) {
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