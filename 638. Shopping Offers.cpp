class Solution {
public:
    
    map < vector< int >, bool > visited;
    map < vector < int >, int > dp;
    
    bool isNoLeft(vector< int >&needs) {
        for( int x: needs ) {
            if( x > 0 ) return false;
        }
        return true;
    }
    int minimumPriceRequire(vector< int >&prices, vector < int >&needs) {
        int sum = 0;
        for(int i = 0 ; i < prices.size() ; i++ ) {
            sum += ( prices[i] * needs[i] );
        }
        return sum;
    }
    bool isPossibleToAcceptTheOffer( vector< int >& offer, vector <int> &needs ) {
        for( int i = 0 ; i < needs.size() ; i++ ) {
            if( needs[i] < offer[i] ) return false;
        }
        return true;
    }
    
    pair<vector < int >, int> upDateAccpetingTheOffer( vector < int >&offer, vector < int > &needs ) {
        vector < int > newNeeds;
        int sum = 0;
        int sz = needs.size();
        for( int i = 0 ; i < sz ; i++ ) {
            int newNeed = needs[i] - offer[i];
            newNeeds.push_back(newNeed);
            
        }
        return make_pair( newNeeds, offer[sz] );
    }
    int DP(vector < int >&prices, vector<vector<int>>& special, vector<int>& needs) {
        if( isNoLeft(needs) ) {
            return 0;
        }
        if( visited.find(needs) != visited.end() ) {
            return dp[needs];
        }
        visited[needs] = true;
        int ret = minimumPriceRequire(prices, needs);
        for( int i = 0 ; i < special.size() ; i++ ) {
            if( isPossibleToAcceptTheOffer(special[i], needs) ) {
                pair < vector < int >, int > updateInfo = upDateAccpetingTheOffer( special[i], needs );
                ret = min( ret, DP( prices, special, updateInfo.first) + updateInfo.second);
            }
        }
        return dp[needs] = ret;
        
        
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return DP( price, special, needs);
    }
};
