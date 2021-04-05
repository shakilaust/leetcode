


class Solution {
public:
    map < pair< long long int, long long int > , bool > dp;
    map < pair< long long int, long long int > , bool > visit;
    unordered_map < long long int, bool > isStone;
    int finishStone; 
    vector < int > stonePlaces;
    
    
    bool isPossible( int x ) {
        return isStone[x] == true;
    }
 
    bool DP( long long int pos, long long int lst ) {
        if( pos == finishStone ) return true;
        if( visit.find(make_pair(pos, lst)) != visit.end()) {
            return dp[make_pair(pos, lst)];
        }
        bool ret = false;
        visit[make_pair(pos, lst)] = true;
        if( pos <= pos + lst - 1 && isPossible( pos + lst - 1 ) ) {
            ret = ret || DP( pos + lst - 1, lst - 1 );
        }
        if( isPossible( pos + lst ) ) {
            ret = ret || DP( pos + lst, lst );
        }
        
        if( isPossible( pos + lst + 1 ) ) {
            ret = ret || DP( pos + lst + 1, lst + 1 );
        }
        return dp[ make_pair(pos, lst)] = ret;
        
           
    }
    
    bool canCross(vector<int>& stones) {
        
        for( int x: stones ) {
            isStone[x] = true;
        }
        finishStone = stones[stones.size() - 1];
        return DP( 0 , 0 );
    }
};
