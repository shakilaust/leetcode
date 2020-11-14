class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int idx = 0;
        int sz = bits.size();
        while( idx < sz ) { 
            if( idx + 1 == sz && bits[idx] == 0 ) return true;
            if( bits[idx] == 1 ) idx += 2;
            else idx += 1;
            
        }
        
        return false;
    }
};
