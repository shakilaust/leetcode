const int NX = 366;
const int INF = 1e9 + 7;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int previousDays[] = {1, 7, 30};
        int dp[ NX ];
        dp[0] = 0;
        
        for( int d = 1, idx = 0 ; d <= 365 ; d++ ) { 

            if( idx < days.size() && d == days[idx] ) { 
                idx++;
                int mn = INF;
                for( int i = 0 ; i < 3 ; i++ ) { 

                    if( d - previousDays[i] >= 0 ) { 
                        mn = min( mn , dp[d - previousDays[i]] + costs[i] );
                    } else mn = min( mn, costs[i] );
                }
                
                dp[d] = mn;
                

            } else dp[d] = dp[d-1];

        }
        
        
        
        return dp[365];
    }
};
