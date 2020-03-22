class WordDistance {
    unordered_map<string, vector< int > > Idx;
public:
    WordDistance(vector<string>& words) {
        Idx.clear();
        for( int i = 0; i < words.size() ; i++ ) { 
            Idx[words[i]].push_back( i + 1 );
        }
    }
    
    int shortest(string word1, string word2) {
        int ans = -1;
        for( int i = 0 ; i < Idx[word1].size(); i++ ) { 
            for( int j = 0 ; j < Idx[word2].size() ; j++ ) { 
                int x = Idx[word1][i];
                int y = Idx[word2][j];
                if( ans == -1 || ans > abs( x - y ) ) { 
                    ans = abs( x - y );
                }
            }
        }
        return ans;

    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
