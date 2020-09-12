class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sz = digits.size();
        vector < int > ans;
        int carry = 1;
        for( int i = sz - 1 ; i >= 0 ; i-- ) { 
            int now = carry + digits[i];
            ans.push_back( now % 10 );
            carry = now / 10;
        }
        
        if( carry > 0 ) ans.push_back( carry );
        reverse( ans.begin(), ans.end());
        return ans;
        
    }
};
