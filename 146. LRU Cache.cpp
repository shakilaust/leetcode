class LRUCache {
private:
   int capacity;
   list < int > recentItems;
   unordered_map < int , list < int > :: iterator > pos;
   unordered_map < int, int > cache;
public:
    LRUCache(int capacity): capacity(capacity) {}
    
    void update(int key) { 
        
        if( pos.find(key) != pos.end() ) { 
            recentItems.erase(pos[key]);
        } else if( recentItems.size() >= capacity ) { 
            
            int lestUsed = recentItems.back();
            recentItems.pop_back();
            cache.erase(lestUsed);
            pos.erase(lestUsed);

        }
        
        
        recentItems.push_front(key);
        pos[key] = recentItems.begin();

    }
    int get(int key) {
      if( cache.find(key) != cache.end()) { 
            update(key);
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        update(key);
        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
