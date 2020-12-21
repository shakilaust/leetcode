
vector < bool > dp, visits;
vector < int > moves;
unordered_map < int, bool > isSquare;

bool DP( int lft ) {
    if( isSquare[lft] ) return true;
   
    if( visits[lft] == true ) return dp[lft];
    visits[lft] = true;
    int sz = moves.size();
    for( int i = 0 ; i < sz ; i++ ) {
        if( moves[i] > lft ) break;
        if( DP( lft - moves[i] ) == false ) return dp[lft] = true;
    }
    return dp[lft] = false;
}

class Solution {
public:
    bool winnerSquareGame(int n) {
        visits.resize(n + 1, false);
        dp.resize(n + 1);
        moves.clear();
        for( int i = 1 ; i <= n / i ; i++ ) {
            isSquare[i * i ] = true;
            moves.push_back( i * i );
        }
        
        return DP(n);
    
    }
};
