class Solution {
    public String longestCommonPrefix(String[] strs) {
        String ans = "";
        int rows = strs.length;
        if( rows == 0 ) return ans;
        int idx = 0;
        boolean ok = true;
        while( ok ) {
            for( int j = 0 ; j < rows; j++ ){
                if( strs[j].length() <= idx ) {
                    ok = false;
                    break;
                }
                if( j > 0 && strs[j].charAt(idx) != strs[j-1].charAt(idx) ) {
                    ok = false;
                    break;
                }
                
            }
            if( ok ) {
                ans += strs[0].charAt(idx);
                idx++;
            }
        }
        return ans;
    }
}
