


class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int rows = graph.size();
        int dp[ 1 << rows ][ rows ];
        for( int i = 0 ; i < ( 1 << rows ) ; i++ ) { 
            for( int j = 0 ; j < rows ; j++ ) { 
                dp[i][j] = ( rows * rows );
            }
        }
        
        for( int i = 0 ; i < rows ; i++ ) { 
            dp[( 1 << i )][i] = 0;
        }

        for( int mask = 0 ; mask < ( 1 << rows ) ; mask++ ) { 

            bool updated = true;
            while(updated) { 
                
                updated = false;
                for( int curNode = 0 ; curNode < rows ; curNode++ ) { 
                    int dist = dp[mask][curNode];
                    int sz = graph[curNode].size();
                    for( int i = 0 ; i < sz ; i++ ) { 

                        int nxtNode = graph[curNode][i];
                        int newMask = ( mask | ( 1 << nxtNode ) );
                        if( dist + 1 < dp[newMask][nxtNode] ) { 

                            dp[newMask][nxtNode] = dist + 1;
                            if(newMask == mask ) { 
                                updated = true;
                            }
                        }
                    }
                }

            }
        }
        
        int ans = rows * rows ;
        for( int i = 0 ; i < rows ; i++ ) { 
            ans = min( ans, dp[( 1 << rows) - 1][i] );
        }
        
        return ans;
    }
};
