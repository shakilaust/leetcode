vector < pair< int, string> > inp;

bool cmp( pair< int, string> a, pair < int, string > b ) {

    if( a.first == b.first ) return a.second < b.second;
    return a.first > b.first;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map < string , int > freq;
        int sz = words.size();
        for( int i = 0 ; i < sz ; i++ ) { 
            freq[words[i]]++;
        }
        
        inp.clear();
        for( auto it: freq) {
          //cout << it.first << " - " << it.second <<endl;
          inp.push_back(make_pair(it.second, it.first));
        }
        
        sort( inp.begin(), inp.end(), cmp );
        
        vector < string > ans;
        for( int i = 0 ; i < k ; i++ ) { 
            ans.push_back(inp[i].second);
        }
        
        
        return ans;
        
        
    }
};
