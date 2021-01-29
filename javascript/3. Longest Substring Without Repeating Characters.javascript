/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let freq = new Array(256).fill(0);
    let low = 0, high = 0, ans = 0;
    while( high < s.length ) {
        let cur = s.charCodeAt(high++) ;
        // console.log('cur', cur);
        freq[cur]++;
        while( freq[cur] > 1 && low < high ) {
            let rv = s.charCodeAt(low++);
            freq[rv]--;
        }
        ans = Math.max( ans, high - low );
    }
    return ans;
};
