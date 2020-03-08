class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector < int > items[4], answer;
        int sz = colors.size();
        for( int i = 0 ; i < sz ; i++ ) { 
            items[colors[i]].push_back(i);
        }
        sz = queries.size();
        
        for( int i = 0 ; i < sz ; i++ ) { 

            int pos = queries[i][0];
            int item = queries[i][1];
            if(items[item].size() > 0 ) {
                int low = lower_bound(items[item].begin(), items[item].end(), pos ) - items[item].begin();
              
                int ans = low == items[item].size() ? -1 : items[item][low] - pos;
                if( low > 0 ) {
                    if( ans > -1 ) {
                        ans = min( ans , pos - items[item][low-1]);
                    } else {
                        ans = pos - items[item][low-1];
                    }
                  //  cout << " items[item][low - 1 ] " << items[item][low - 1 ];
                }
               
                answer.push_back(ans);
            } else {
                answer.push_back(-1);

            }
        }
        
        return answer;
        
    }
};
