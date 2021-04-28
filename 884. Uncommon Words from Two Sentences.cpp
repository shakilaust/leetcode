class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        map < string, int > freq;
        stringstream ss(A);
        string x;
        while( ss >> x) {
            freq[x]++;
        }
        
        stringstream sn(B);
        while( sn >> x ) {
            freq[x]++;
        }
        
        vector < string > ans;
        for( auto now: freq) {
            if( now.second == 1 ) {
                ans.push_back( now.first);
            }
        }
        
        return ans;
    }
};
