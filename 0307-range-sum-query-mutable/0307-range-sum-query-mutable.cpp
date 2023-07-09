class NumArray {
public:
    vector<int> bTree;
    vector<int> arr;
    
    NumArray(vector<int>& nums) {
        int n = nums.size();
        bTree = vector<int>(n+1,0);
        arr = nums;
        for(int i=0;i<n;i++)
            updateTree(i,arr[i]);
    }
    
    void updateTree(int i,int val){
        i = i+1;
        while(i<=arr.size()){
            bTree[i]+=val;
            i+=i&(-i);
        }
    }
    
    int sumTree(int i){
        int sum = 0;
        i = i+1;
        while(i>0){
            sum+=bTree[i];
            i-=i&(-i);
        }
        return sum;
    }
    
    void update(int i, int val) {
        
        int diff = val-arr[i];
       arr[i] = val;
        i = i+1;
        
        while(i<=arr.size()){
            bTree[i]+=diff;
            i+=i&(-i);
        }
    }
    
    int sumRange(int left, int right) {
        return sumTree(right)-sumTree(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */