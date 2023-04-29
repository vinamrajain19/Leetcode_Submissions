// Intuition
/* Sort both the array weight wise and traverse until queries is smaller then edgeList
Approach
1. Make a parent array and initialize it with themselves.
2. Make a answer array and initislize it with false.
3. Swap the first and third part of edgeList to sort it w.r.t weight.
4. Sort edgeList.
5. Make an array to store the weights of the queries vector and their index.
6. Traverse in the edgeList until its weight is greater than queries weight.
7. Make their parents same in the loop which has been traversed.
8. Outside the loop check if they have same parents means they can be traversed so make them true. */ 



class Solution {
public:
    int dsu(vector<int>& parent,int x)
    {
        //Base case
        if(parent[x] == x)
            return x;
        //Else check its parent
        else
            return parent[x] = dsu(parent,parent[x]);
        
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) 
    {
        //A parent vector to store the parent of the elements
        vector<int> parent(n,-1);

        //Answer vector to store the answer
        vector<bool> ans(queries.size(),false);

        //Make every element its own parent
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        //Swap the weight index with the first index so that we can sort it by weight
        for(int i=0;i<edgeList.size();i++)
            swap(edgeList[i][0],edgeList[i][2]);

        //Sort by Weight
        sort(edgeList.begin(),edgeList.end());

        //Store the queries weight and its index
        vector<pair<int,int>> arr;

        for(int i=0;i<queries.size();i++)
            arr.push_back({queries[i][2],i});
        
        //Sort the queries w.r.t weight
        sort(arr.begin(),arr.end());


        int j = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            //Traverse until query weight is greater than the edge weight
            while(j < edgeList.size() && edgeList[j][0] < arr[i].first)
            {    
                //Take the vertices of the edgelist
                int u = edgeList[j][1],v = edgeList[j][2];
                //Check their parents
                int pu = dsu(parent,u),pv = dsu(parent,v);
                //If not equal make them equal
                if(pu != pv)
                    parent[pu] = pv;
                
                j++;
            }
            //Take the vertices of the query 
            int x = queries[arr[i].second][0],y = queries[arr[i].second][1];
            //Check their parents
            int px = dsu(parent,x),py = dsu(parent,y);
            //If parents are equal then return true
            if(px == py)
                ans[arr[i].second] = true;
            
        }
        return ans;

    }
};