
vector < pair< long long int, int > > inp;
const int mod = 1e9 + 7;

bool cmp( pair< long long int, int > a, pair< long long int, int > b ) { 
     return a.first < b.first;
}


int adjustValue( int value ) { 
    
     value = value % mod;
    return value;
}


class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        inp.clear();
        for( int i = 0 ; i < n ; i++ ) { 
            inp.push_back(make_pair(efficiency[i], speed[i]));
        }
        
        sort(inp.begin(), inp.end(), cmp);
        priority_queue <int, vector<int>, greater<int> > pq; 
        long long int ans = 0, sum = 0;
        for( int i = n - 1 ; i >= 0 ; i--) { 
            long long int a = ( sum + inp[i].second );
            ans = max( ans , ( a * inp[i].first ) );
            if( k > 1 ) {
                if( pq.size() < k - 1 ) { 
                    pq.push(inp[i].second);
                    sum += inp[i].second;
                } else {
                 
                    if( pq.top() < inp[i].second ) { 

                        sum -= pq.top();
                        sum += inp[i].second;
                       
                        pq.pop();
                        pq.push(inp[i].second);
                    }
                }

            }
            
       
            
            
        }
        return ans % mod;
    }
};
