class Solution {
public:
    int romanToInt(string s) {
        unordered_map < string, int > romanDigit;
        romanDigit["M"] = 1000;
        romanDigit["D"] = 500;
        romanDigit["C"] = 100;
        romanDigit["L"] = 50;
        romanDigit["X"] = 10;
        romanDigit["V"] = 5;
        romanDigit["I"] = 1;
        
        int sum = 0;
        int idx = 0;
        int sz = s.size();
        while( idx < sz ) {
            string curSymbol = s.substr(idx, 1);
            int curValue = romanDigit[curSymbol];
            int nxtValue = 0;
            if( idx + 1 < sz ) {
                string nxtSymbol = s.substr(idx+1, 1);
                nxtValue = romanDigit[nxtSymbol];
            }
            
            if( curValue < nxtValue ) {
                sum += ( nxtValue - curValue );
                idx += 2;
            } else {
                sum += curValue;
                idx += 1;
            }
        }
        return sum;
        
    }
};
