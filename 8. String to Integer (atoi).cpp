class Solution {
public:
    int myAtoi(string s) {
        bool neg = false;
        long long int value = 0;
        stringstream ss(s);
        string word;
        
        bool foundDigits = false;
      //  cout << " INT_MIN " << INT_MIN << endl;
        
        while( ss >> word ) {
            int sz = word.size();
            int startIdx = 0;
            if( word[startIdx] == '-' || word[startIdx] == '+' ) {
                if( word[startIdx] == '-' ) neg = true;
                startIdx++;
            }
            for( int i = startIdx ; i < sz ; i++ ) {
                if( word[i] >= '0' && word[i] <= '9' ) {
                     int val = word[i] - '0';
                
                     value = ( value * 10 ) + val;
                    if( ( neg == false && value >= INT_MAX) || ( neg && value * -1 <= INT_MIN ) ) {
                        if( neg ) return INT_MIN;
                        return INT_MAX;
                    }
                    
                } else {
                    break;
                }
               
            }
            break;
        }
        
        if( neg ) value *= -1;
        return value;
    }
};
