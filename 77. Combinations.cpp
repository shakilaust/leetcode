



class Solution {
public:
    vector < vector < int > > ans;
    void dfs( int start, int lft, int n, vector < int > &tmp ) {
        if( lft == 0 ) {
            ans.push_back( tmp );
            return;
        }
        if( start > n ) return ;
        for( int i = start ; i <= n ; i++ ) {
            tmp.push_back( i );
            dfs( i + 1 , lft - 1 , n , tmp );
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector < int > tmp;
        ans.clear();
        dfs( 1 , k , n , tmp );
        return ans;
    }
};
