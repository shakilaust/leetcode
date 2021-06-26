

bool cmp( pair < int, int > a, pair < int, int > b ) {
    if( a.first == b.first ) {
        return a.second < b.second;
    }
    
    return a.first > b.first;
}



int getMinValue( int low, int high, vector < int > &nums ) {
    int mn = nums[low];
    for( int i = low + 1 ; i <= high ; i++ ) {
        mn = min( nums[i] , mn );
    }
    
    return mn;
}
class Solution {
public:
 
    long long maxAlternatingSum(vector<int>& nums) {
        int sz = nums.size();
        if( sz == 0 ) {
            return 0;
        }
        vector < pair< int, int > > inp;
        for( int i = 0 ; i < sz ; i++ ) {
            inp.push_back( make_pair( nums[i], i ) );
        }
        sort( inp.begin(), inp.end() , cmp );
        set < int > willAdd;
        set < int > taken;
        for( int i = 0 ; i < sz ; i++ ) {
            if( taken.count(inp[i].second + 1) == 0 &&  taken.count(inp[i].second - 1 ) == 0 ) {
                willAdd.insert(inp[i].second);
            }
            taken.insert( inp[i].second );
        }
        
        long long int ans = 0;
        int lst = -1;
        for( int x: willAdd ) {
            ans += nums[x];
            if( lst != -1 ) {
                ans -= getMinValue( lst + 1 , x - 1 , nums);
               
            }
            
         
            lst = x;
        }
        
        return ans;
        
        
        
      
    }
};
