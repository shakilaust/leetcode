class Solution {
public:
    vector<int> asteroidCollision(vector<int>& inp) {
        vector < int > ans;
        for( int i = 0 ; i < inp.size() ; i++ ) {
            ans.push_back( inp[i] );
            bool update = true;
            while( ans.size() > 1 && update ) { 
                update = false;
                if( ans[ans.size() - 1 ] < 0 &&  ans[ans.size() - 2] > 0 ) { 
                     update = true;
                    if( abs(ans[ ans.size() - 1 ] ) == abs( ans[ans.size() - 2] ) ) {
                        ans.pop_back();
                        ans.pop_back();
                    } else { 
                        
                        if( abs(ans[ans.size() - 1 ] ) > abs( ans[ans.size() - 2 ])) {
                            ans[ans.size() - 2 ] = ans[ ans.size() - 1 ];
                            ans.pop_back();
                        } else {
                            ans.pop_back();

                        }
                        
                       

                    }
                }
            }
        }
        
        return ans;
    }
};
