


void dfs( int pos, int sz, string now, string &s, vector < vector < string > > &ans, vector < string> &cur, set < vector<string> > &chk,  vector < vector < bool > > &isPalindrome) { 

    if( pos == sz ) { 
        if(chk.find(cur) == chk.end()) { 
            chk.insert(cur);
            ans.push_back(cur);
            return;
        }
    }
    
    now += s[pos];
    cur.push_back(now) ;
    dfs( pos + 1, sz , "", s , ans , cur , chk, isPalindrome );
    cur.pop_back();
    
    for( int i = pos + 1 ; i < sz ; i++ ) { 
        now += s[i];
        if(isPalindrome[pos][i]) { 
          
            cur.push_back(now);
            dfs( i + 1 , sz , "" , s , ans , cur , chk, isPalindrome );
            cur.pop_back();

        }
    }

}

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int sz = s.size();
        vector < vector < bool > > isPalindrome( sz , vector < bool > ( sz , false ) );
        
        for( int i = 0 ; i < sz ; i++  ) { 
            
            isPalindrome[i][i] = true;
            for( int x = i, y = i + 1 ; x >= 0 && y < sz && s[x] == s[y] ; x--, y++ ) { 
                isPalindrome[x][y] = true;
            }
            
             for( int x = i - 1, y = i + 1 ; x >= 0 && y < sz && s[x] == s[y] ; x--, y++ ) { 
                isPalindrome[x][y] = true;
            }
            

        }
        
        vector < string > cur;
        vector < vector < string > > ans;
        set < vector<string >> chk;
        dfs( 0, sz , "", s , ans, cur, chk , isPalindrome );
        return ans;
    }
};
