#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        int start_idx, end_idx, mx = 0;
        for( int i = 0 ; i < sz ; i++ ) { 
            for( int j = i ; j < sz ; j++ ) {
                bool isPlaindrome = true;
                for( int x = i, y = j ; x < y ; y--, x++ ) { 
                    if( s[x] != s[y] ) {
                        isPlaindrome = false;
                        break;
                    }
                }
                if( isPlaindrome ) {
                    if( j - i + 1 > mx ) { 
                            mx = j - i + 1;
                            start_idx = i;
                            end_idx = j;
                    }
                }
            }
        }
        
        string ans = "";
        for( int i = start_idx ; i <= end_idx ; i++ ) ans += s[i];
        return ans;
        
    }
};
