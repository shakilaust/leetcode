class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector < int > notMatchingIndexes;
        for( int i = 0 ; i < s1.size(); i++ ) {
            if( s1[i] != s2[i] ) {
                notMatchingIndexes.push_back(i);
            }
        }
        if( notMatchingIndexes.size() > 2 ) return false;
        else if( notMatchingIndexes.size() == 0 ) return true;
        else if( notMatchingIndexes.size() == 1 ) return false;
        else {
            // sawp first string
            int f = notMatchingIndexes[0];
            int s = notMatchingIndexes[1];
            swap( s1[f], s1[s] );
            if( s1 == s2 ) return true;
            swap( s1[f], s1[s] );
            swap( s2[f], s2[s] );
            if( s1 == s2 ) return true;
            return false;
        }
    }
};
