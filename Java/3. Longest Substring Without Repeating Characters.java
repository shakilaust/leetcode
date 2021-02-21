class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ans = 0;
        int[] freq = new int[265];
        Arrays.fill(freq, 0);
        int low = 0, high = 0;
        while( high < s.length() ) {
            int idx = s.charAt(high++);
            freq[idx]++;
            while( freq[idx] > 1 ) {
                int lowIdx = s.charAt(low);
                freq[lowIdx]--;
                low++;
            }
            ans = Math.max(ans, high - low );
            
        }
        return ans;
    }
}
