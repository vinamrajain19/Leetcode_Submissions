class LRUCache {
public:
    class node{
        public :
        int key;
        int val;
        node * next;
        node * prev;
        node(int k,int v){
            key = k;
            val = v;
        }
    };
    
    node * head = new node(-1,-1);
    node * tail = new node(-1,-1);
    
    int cap;
    unordered_map<int,node *> m;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    
    void addnode(node * n){
        node * t = head -> next;
        n->next = t;
        n->prev = head;
        t->prev  = n;
        head -> next = n;
    }
    
    void deletenode(node * d){
        node * dprev = d -> prev;
        node * dnext = d -> next;
        
        dprev -> next = dnext;
        dnext -> prev = dprev;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            node * temp_node = m[key];
            int temp = temp_node->val;
            
            m.erase(key);
            deletenode(temp_node);
            addnode(temp_node);
            
            m[key] = head->next;
            return temp;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            node * e = m[key];
            m.erase(key);
            deletenode(e);
        }
        
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new node(key,value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */