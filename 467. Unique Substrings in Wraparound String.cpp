
int ok( int a, int b)  {

    int dif  = a - b;
    if( dif < 0 ) dif += 26;
    return dif == 1;

}


class Solution {
public:
    int findSubstringInWraproundString(string p) {
        
        
        int freqChar[26] = {0};
        int sz = p.size();
        int curLength = 0;
        for( int i = 0 ; i < sz ; i++ ) { 

            if( i == 0 ) curLength = 1;
            else if( ok(p[i] - 'a', p[i-1] - 'a')) curLength++;
            else curLength = 1;
            freqChar[p[i]-'a'] = max(freqChar[p[i]-'a'] , curLength);
        }
        
        for( int i = 1 ; i < 26 ; i++ ) freqChar[i] += freqChar[i-1];
        return freqChar[25];
    }
};
