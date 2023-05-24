class Solution {
public:
  
    //  the optimal solution is realize When you hire someone with X ratio, is not possible for you to hire someone who's ratio is lower! Since they will definitely be unhappy, that's why sort according to ratio
    
    //Need to store the wage/quality ratio & quality for each worker and sort it 
//Now traverse worker and store it in a k-max heap, where heap stroes the quality with top max quality at top.
//keep on storing sum of each quality of k elements stored in pq.
//As we move from lower ratio worker to higher ratio, when stored k elements in queue then evaluate the total wage by multiplying highest ratio with the sum of all quality stored till now.
//To minimize the overall wage, we need to remove the largest quality from the queue
    
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        vector<pair<double,int>> vec;
        
        for(int i = 0 ; i < quality.size() ; i++){
            vec.push_back(make_pair(double(wage[i])/quality[i],quality[i]));
        }
        
        // sort vector by ratio 
        sort(vec.begin(),vec.end());
        
        
        double ans = 1e9;
        int quality_count = 0;
        
        priority_queue<int> q;
        
        for(int i = 0 ; i < vec.size(); i++){
            q.push(vec[i].second); 
            
            // add quality into total 
            quality_count += vec[i].second;
            
            // rule out the extra quality since we have more than k people
            // we rule out the people that cost most quality 
            if(q.size() > k){
                int extra_q = q.top();
                q.pop();
                quality_count = quality_count - extra_q;
            }
            
            if(q.size() == k){
                ans = min(ans, vec[i].first * quality_count);
            }
        }   
        return ans;
    }
};