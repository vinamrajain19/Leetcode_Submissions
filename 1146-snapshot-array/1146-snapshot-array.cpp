class SnapshotArray {
public:
    
    vector<vector<pair<int,int>>> v;
    int id = -1;
    SnapshotArray(int length) {
        v.resize(length);
        for(int i = 0;i<length;i++){
            v[i].push_back({-1,0});
        }
    }
    
    void set(int index, int val) {
        v[index].push_back({id,val});
    }
    
    int snap() {
         id++;
         return id;
    }
    
    int get(int index, int snap_id) {
        int s = 0;
        int e = v[index].size()-1;
        int ans = 0;
        while(s <= e){
            int m = (s+e)/2;
            
            if(v[index][m].first < snap_id){
                ans = m;
                s = m+1;
            }
            else e= m-1;
        }
        return v[index][ans].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */