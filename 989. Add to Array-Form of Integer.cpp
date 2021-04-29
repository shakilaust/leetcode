class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector < int > ans;
        vector < int > add;
        while( k > 0 ) {
            add.push_back( k % 10 );
            k /= 10;
        }
        reverse( add.begin(), add.end() );
        int i = num.size() - 1;
        int j = add.size() - 1;
        int carry = 0;
        while( i >= 0 || j >= 0 || carry > 0 ) {
            int tmp = carry;
            if( i >= 0 ) {
                tmp += num[i--];
            }
            if( j >= 0 ) {
                tmp += add[j--];
            }
            ans.push_back( tmp % 10 );
            carry = tmp / 10;
        }
        reverse( ans.begin(), ans.end() );
        return ans;
    }
};
