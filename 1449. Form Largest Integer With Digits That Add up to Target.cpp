const int NX = 5005;

bool vis[ NX ];
pair< string, bool> dp[ NX ];


pair< string, bool> DP( int left, vector< int > &cost) {
    
    if( left == 0 ) return make_pair("", true);
    pair<string, bool> &ret = dp[left];
    if( vis[left] ) return ret;
    ret = make_pair("", false);
    vis[left] = true;
    for( int i = 1 ; i <= 9 ; i++ ) {
        if( cost[i-1] <= left ) {
            pair< string, bool> now =  DP( left - cost[i-1] , cost );
            if( now.second == false ) continue;
            string tmp = to_string(i) + now.first;
            if( tmp.size() > ret.first.size() || ( tmp.size() == ret.first.size() && tmp > ret.first ) ) {
                ret.first = tmp;
                ret.second = true;
            }
        }
    }
    
    return ret;
    
}

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        for(int i = 0 ; i <= target ; i++ ) {
            vis[i] = false;
        }
        
        string ans = DP( target, cost ).first;
        return ans == "" ? "0" : ans;
    }
};
