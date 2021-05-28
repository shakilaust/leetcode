class Solution {
public:
    string shortestPalindrome(string s) {
        string revStr = s;
        reverse( revStr.begin(), revStr.end());
        string newStr = s + "%" + revStr;
        
        vector < int > kmpTable( newStr.size() , 0 );
        int cnt = 0;
        int len = newStr.size();
        for( int i = 1 ; i < len ; i++ ) {
            while( cnt > 0 && newStr[i] != newStr[cnt] ) {
                cnt = kmpTable[cnt-1];
            }
            if( newStr[i] == newStr[cnt] ) cnt++;
            kmpTable[i] = cnt;
        }
        
        string ans = revStr.substr(0, s.size() - kmpTable[len-1]) + s;
        return ans;
        
        
            
    }
};
