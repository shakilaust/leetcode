
vector < pair< int, int > > queens;
bool ok( int x, int y ) {
    int sz = queens.size();
    for( int i = 0 ; i < sz ; i++ ) {
       if( x == queens[i].first ) return false;
       if( y == queens[i].second ) return false;
        if( abs( x - queens[i].first ) == abs( y - queens[i].second) ) return false;
    }
    
    return true;
}

int dfs( int n, int row, int col ) {
    if( row == n ) {
        return queens.size() == n;
    }
    int ans = 0;
    if( col == n ) {
        return dfs( n , row + 1 , 0  );
    }
    if( ok( row, col) ) {
        queens.push_back({ row, col } );
        ans += dfs(n, row + 1 , 0  );
        queens.pop_back();
    }
    ans += dfs( n, row, col + 1 );
    return ans;
}



class Solution {
public:
    int totalNQueens(int n) {
        return dfs( n, 0, 0 );
    }
};
