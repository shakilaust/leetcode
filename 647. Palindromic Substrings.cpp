class Solution {
public:
    int countSubstrings(string s) {
        int sz = s.size();
        bool isPalindrome[sz+1][sz+1];
        int dp[sz+1];
        for( int i = 0 ; i < sz ; i++ ) { 
            for( int j = 0 ; j < sz ; j++ ) isPalindrome[i][j] = false;
        }
        int ans = 0;
        for( int i = 0 ; i < sz ; i++ ) { 
            isPalindrome[i][i] = true;
            ans++;
            for( int x = i, y = i+1 ; y < sz && x >= 0 && s[x] == s[y] ; x--, y++ )  {
                if(isPalindrome[x][y] == false ) { 
                    isPalindrome[x][y] = true;
                    ans++;
                }
            }
            for( int x = i - 1 , y = i + 1 ; y < sz && x >= 0 && s[x] == s[y] ; x--, y++ ) {
                if(isPalindrome[x][y] == false ) { 
                    isPalindrome[x][y] = true;
                    ans++;
                }
            }
        }
        return ans;
        
    }
};
