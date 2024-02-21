class LRUCache {
public:
    unordered_map<int, int> m;
    list<int> l;
    unordered_map<int,list<int>::iterator> address;
    int cap ;
    int size =0;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        l.erase(address[key]);
        address.erase(key);
        l.push_front(key);
        address[key] = l.begin();
        
        return m[key];
        
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            l.erase(address[key]);
            address.erase(key);
            l.push_front(key);
            m[key] = value;
            address[key] = l.begin();
        }else{
             if(size == cap){
                
                int k = l.back();
                l.pop_back();
                m.erase(k);
                address.erase(k);
                size--;
            }
        
            size++;
            m[key] = value;
            l.push_front(key);
            address[key] = l.begin();
 
        }
           

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */