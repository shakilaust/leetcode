  struct abc { 
        int value, freq;
    };

    bool cmp(abc A, abc B) { 
        return A.freq > B.freq;
    }

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector < abc > inp;
        map < int, int > cnt;
        for( auto i: nums) cnt[i]++;
        for( auto i: cnt ) {
            abc tmp;
            tmp.value = i.first;
            tmp.freq = i.second;
            inp.push_back(tmp);
        }
        sort( inp.begin(), inp.end(), cmp );
        vector < int > ans;
        int sz = inp.size();
        for( int i = 0 ; i < k ; i++ ) ans.push_back(inp[i].value);
        return ans;
    }
};
