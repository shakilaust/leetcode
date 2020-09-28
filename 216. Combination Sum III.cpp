class Solution {
public:
    
    unordered_map < int , bool > taken;
    
    void dfs( int k, int rem, int mask, vector < vector < int > > &ans, vector < int > &now ) {
        
       if( taken.find(mask) != taken.end() ) return;
        taken[mask] = true;
        if( k == 0 ) { 
            if( rem == 0 ) {
                ans.push_back(now);
            }
            return;
        }
        
        if( rem == 0 ) return;
        
        for( int i = 1 ; i <= 9 ; i++ ) { 
          
            if( (mask &  1 << i ) == 0 ) { 
              
                 if( rem - i >= 0 ) { 
                    now.push_back(i);
                    dfs( k - 1 , rem - i , mask | ( 1 << i ) , ans , now);
                    now.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector < vector < int > > ans;
        vector < int > now;
        taken.clear();
        dfs( k, n, 0, ans, now );
        return ans;
    }
};
