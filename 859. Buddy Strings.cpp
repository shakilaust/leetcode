class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if( s.size() != goal.size() || s.size() < 2 ) {
            return false;
        }
        vector < int > pos;
        int freq[26] = {0};
        bool multiple = false;
        for( int i = 0 ; i < s.size() ; i++ ) {
            if( s[i] != goal[i] ) {
                pos.push_back(i);
            }
            if( pos.size() > 2 ) return false;
            freq[s[i] - 'a']++;
            if( freq[s[i] - 'a'] > 1 ) {
                multiple = true;
            }
        }
        if( pos.size() == 1 ) return false;
        else if( pos.size() == 0 ) { 
            return multiple;
        }
        swap( s[pos[0]], s[pos[1]]);
        return s == goal;
    }
};
