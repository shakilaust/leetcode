class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        int freq[10] = {0};
        int sz = secret.size();
        for( int i = 0 ; i < sz ; i++ ) {
            if( secret[i] == guess[i] ) {
                bulls++;
            } else freq[secret[i] - '0']++;
        }
        
        for(int i = 0 ; i < sz ; i++ ) {
            if( secret[i] != guess[i] && freq[guess[i] - '0'] > 0 ) {
                freq[guess[i] - '0']--;
                cows++;
            }
        }
        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};
