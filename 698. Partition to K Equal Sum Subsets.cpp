
const int NX = ( 1 << 16 );

bool vis[ NX + 5 ][ 16 ], dp[ NX + 5 ][ 16 ];


bool DP( vector < int > &nums, int &target, int mask, int curSum, int remK ) { 

    if( remK == 0 ) return true;
    bool &ret = dp[ mask ][ remK ];
    if( vis[ mask ][ remK ] ) return ret;
    vis[ mask ][ remK ] = true;
    ret = false;
    
    for( int i = 0 ; i < nums.size(); i++ ) { 

        if( mask & ( 1 << i ) ) continue;
        if( curSum + nums[i] > target ) continue;
        if(DP( nums , target , mask | ( 1 << i ) ,  curSum + nums[i] == target ? 0 : curSum + nums[i] , curSum + nums[i] == target ? remK - 1 : remK )) return ret = true;

    }
    
    
    return ret;

}

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        int sz = nums.size();
        for( int i = 0 ; i < sz ; i++ ) { 

            sum += nums[i];
        }
        
        if( sum % k != 0 ) return false;
        int target = sum / k;
        for( int i = 0 ; i < ( 1 << sz ) + 1 ; i++ ) { 
            for( int j = 0 ;  j <= k ; j++ ) { 
                vis[i][j] = false;
            }
        }
        return DP(nums, target, 0, 0, k );
        
    }
};
