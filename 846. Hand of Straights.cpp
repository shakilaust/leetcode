class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if( hand.size() % W != 0 ) { 
            return false;
        }
        unordered_map < int, int > freq;
        set < int > s;
        
        for( int i = 0 ; i < hand.size() ; i++ ) {
            s.insert(hand[i]);
            freq[hand[i]]++;
        }
        
        for(auto element: s ) { 
    
            while(freq[element] >  0 ) {
                for( int currentItem = element, i = 0 ; i < W ; currentItem++ , i++ ) { 
                    if( freq[currentItem] == 0 ) return false;
                    freq[currentItem]--;
                }
            }
        }
        
        
        
        return true;
        


    }
};
