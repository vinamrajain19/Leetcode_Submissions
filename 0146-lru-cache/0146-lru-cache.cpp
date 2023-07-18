class LRUCache {
public:
    unordered_map<int, pair<list<int>::iterator, int>> ht;
    list<int> dll;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    void moveToFirst(int key){
        dll.erase(ht[key].first);
        dll.push_front(key);
        ht[key].first=dll.begin();
    }
    
    int get(int key) {
        if(ht.find(key)==ht.end()) return -1;
        
        moveToFirst(key);
        return ht[key].second;
    }
    
    void put(int key, int value) {
        if(ht.find(key)!=ht.end()){
            ht[key].second=value;
            moveToFirst(key);
        }
        else{
            dll.push_front(key);
            ht[key]={dll.begin(), value};
            cap--;
        }
        
        if(cap<0){
            ht.erase(dll.back());
            dll.pop_back();
            cap++;
        }
        
    }
};

/*
Algorithm Outline:

LRUCache()
1. key -> (addr, value)
2. List, will contain keys
3. cap=capacity

Get
1. if found, movetofirst for key, return. Else -1

Put
1. if exist, update.
2. else add
3. move to first
4. if >capacity, remove last in list i.e. LRU

Move to first
1. erase element
2. add to first
3. store first addr in ht
 */