class Solution {
    public String minWindow(String s, String t) {
        String ans = "";
        int[] freqNeed = new int[255];
        int[] freqHas = new int[255];
        Arrays.fill(freqNeed, 0 );
        Arrays.fill( freqHas, 0 );
        int needUniqueChar = 0;
        for( int i = 0 ; i < t.length() ; i++ ) {
            int idx = t.charAt(i);
            freqNeed[idx]++;
            if( freqNeed[idx] == 1 ) needUniqueChar++;
        }
        
        int uniqueChar = 0;
        
        int low = 0, high = 0;
        while( high < s.length() ) {
            int idx = s.charAt(high);
            freqHas[idx]++;
            if( freqHas[idx] == freqNeed[idx] ) uniqueChar++;
            while( needUniqueChar == uniqueChar ) {
                if( ans == "" || ans.length() > ( high - low + 1 ) ) {
                    ans = s.substring(low, high + 1 );    
                }
                int removeLow = s.charAt(low) ;
                low++;
                freqHas[removeLow]--;
                if( freqHas[removeLow] < freqNeed[removeLow] ) {
                    uniqueChar--;
                }
            }
            high++;
        }
        
        
        return ans;
    }
}
