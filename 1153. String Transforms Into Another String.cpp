class Solution {
public:
    bool canConvert(string one, string two) {
        if( one == two ) return true;
        if( one.size() != two.size() ) return false;
        int converted[26] = {0};
        int taken[26] = {0};
        for( int i = 0 ; i < 26 ; i++ ) { 
            converted[i] = i;
        }

        for( int i = 0 ; i < one.size() ; i++ ) { 

            int o = one[i] - 'a';
            int t = two[i] - 'a';
            o = converted[o];
            if( o == t ) continue;
            else { 
                if( converted[one[i] - 'a'] == one[i] - 'a' ) { 
                    converted[one[i] - 'a'] = t;
                } else return false;
            }
        }
        return set( two.begin(), two.end() ).size() < 26 ;
        
    }
};
