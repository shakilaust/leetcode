/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */

var isOk = function(a, b) {
    for( let i = 0 ; i < 26 ; i++ ) {
        
        if( a[i] != b[i] ) {
            return false;
        }
    }
    return true;
}
var checkInclusion = function(s1, s2) {
    let freq1 = new Array(26).fill(0);
    let freq2 = new Array(26).fill(0);
    let sz = s1.length;
    for( var i = 0 ; i < sz ; i++ ) {
        
        let idx = s1.charCodeAt(i)- 97;
        freq1[idx]++;
    }
    
   
    let ans = false;
    let low = 0;
    for( let i = 0 ; i < s2.length && !ans; i++ ) {
        let idx = s2.charCodeAt(i)- 97;
        freq2[idx]++;
        if( i - low + 1 == sz ) {
            ans = isOk(freq1, freq2);
            idx = s2.charCodeAt(low)- 97;
            freq2[idx]--;
            low++;
        }
        
    }
    
    return ans;
    
    
};
