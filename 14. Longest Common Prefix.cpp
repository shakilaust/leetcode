class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int rows = strs.size();
        if( rows == 0 ) return "";
        int mnCharStringLength = strs[0].size();
        for( int i = 1 ; i < rows ; i++ ) { 
            if( mnCharStringLength > strs[i].size() ) {
                mnCharStringLength = strs[i].size();
            }
        }
        
        string ans = "";
        bool ok = true;
        for( int i = 0 ; i < mnCharStringLength && ok ; i++ ) {
            
           
            for( int row = 1 ; row < rows && ok; row++ ) {
                if(strs[row][i] != strs[row-1][i] ) {
                    ok = false;
                }
            }
            
            if( ok ) {
                ans += strs[0][i];
            }

        }
        return ans;
    }
};
