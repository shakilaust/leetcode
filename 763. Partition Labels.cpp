class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        vector < int > ans;
        int last[26];
        for( int i = 0 ; i < S.size() ; i++ ) { 
            last[S[i] - 'a'] = i;
        }
        
        int mx = 0, prv = 0;
        for( int i = 0 ; i < S.size() ; i++ ) { 
            mx = max( mx, last[S[i] - 'a'] );
            if( i == mx ) { 
                ans.push_back(i - prv + 1 );
                prv = i + 1;
            }

        }
        
        return ans;
        
    }
};
