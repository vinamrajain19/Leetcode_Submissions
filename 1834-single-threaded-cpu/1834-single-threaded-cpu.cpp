class Solution {
public:

    // We need to add initial indexes to the final answer so I added index i to all the tasks, then I sorted the task using the arriving time. Then made a min heap of pair of integer, a time variable to maintain the current time. Now simply checking if the time of the current taks is less than or equal to the current time, and enquing them.
//  The catch is on empty queue, jump to the current items time.


    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0;i<n;i++)
        {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        vector<int> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int i=0;
        long long int time=tasks[0][0];
        while(!pq.empty() || i<n)
        {
            while(i<n && time>=tasks[i][0])
            {
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            if(pq.empty())
                time=tasks[i][0];
            else
            {
                time+=pq.top().first;
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};