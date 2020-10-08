class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        n--;
        while( n >= 0 ) {
            ans = ( (char) (n % 26 + 'A') ) + ans;
            n /= 26;
            n--;
        }
        
        return ans;
        
    }
};
