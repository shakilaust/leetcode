class RandomizedSet {
    set < int > values;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        values.empty();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if( values.find(val) == values.end() ) {
            values.insert( val );
            return true;
        }
        
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if( values.find(val) != values.end()) {
            values.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % values.size();
        set < int > :: iterator it = values.begin();
        while( idx-- ) it++;
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
