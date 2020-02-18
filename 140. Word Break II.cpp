
vector < vector < int > > hasStart;
int len;
set < string > taken;

void generateAllAnswer(int pos, vector < string > &ans,  vector<string>& W, string cur) { 

    if( pos == len ) { 
        if( taken.find(cur) == taken.end() ) { 
            ans.push_back(cur);
            taken.insert(cur);
        }
        
        
        return;
    }
    
    int sz = hasStart[pos].size();
    for( int j = 0 ; j < sz ; j++ ) { 
        string add;
        if( pos == 0 )  { 
            add = W[hasStart[pos][j]];
        } else {
            add = " " + W[hasStart[pos][j]];
        }
        generateAllAnswer( pos + W[hasStart[pos][j]].size() , ans , W , cur + add );
    } 

}


class Solution {

public:
    vector<string> wordBreak(string s, vector<string>& W) {
        len = s.size();
        int nsz = W.size();
        vector < bool > dp ( len + 1 , false );
        
        taken.clear();
        hasStart.clear();
        dp[ 0 ] = true;
        vector < int > dummy;
        
        for( int i = 1 ; i <= len ; i++ ) { 
            hasStart.push_back(dummy);
            for( int j = 0; j < nsz ; j++ ) { 
                
                int Wlen = W[j].size();
                int startingIdx = i - W[j].size();
                if( startingIdx >= 0 && dp[ startingIdx ]  ) {
                    if( s.substr(startingIdx , Wlen ) == W[j] ) { 
                        dp[i] = true;
                        hasStart[startingIdx].push_back(j);
                    }   
                }
            }
        }
        
        vector < string > ans;
        
        if( dp[len] == false ) { 
            return ans;
        }
        
        generateAllAnswer( 0 , ans, W, "" );
        return ans;
    }
};
