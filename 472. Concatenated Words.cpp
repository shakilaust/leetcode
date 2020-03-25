unordered_map < string, bool > presents;


bool cmp( string a, string b) { 

    return a.size() < b.size();
}

bool isPossible(string word) { 

    if(presents.size() == 0) return false;
    vector < bool > dp( word.size() + 1 , false );
    dp[0] = true;
    for( int i = 1 ; i <= word.size() ; i++ ) { 

        for( int j = 0 ; j < i  && !dp[i] ; j++  )
        {
            if( dp[j] == false ) continue;
            if(presents[word.substr(j, i - j)]) { 
                dp[i] = true;
            }
        }
    }
    
    return dp[word.size() ];
    
}


class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort( words.begin(), words.end(), cmp );
        presents.clear();
        vector < string > ans;
        for( int i = 0 ; i < words.size() ; i++ ) { 
            if(isPossible(words[i])) ans.push_back(words[i]);
            presents[words[i]] = true;
        }
        
        return ans;
    }
};
