class Solution {
public:
    string frequencySort(string s) {
        priority_queue< pair< int, char > > pq;
        int freq[255] = {0};
        for( int i = 0 ; i < s.size() ; i++ ) { 
            freq[s[i]]++;
        }
        
        for( int i = 0 ; i < 255 ; i++ ) { 
            if(freq[i] > 0 ) { 
                pq.push(make_pair(freq[i], i ));
            }
        }
        string ans = "";
        while(!pq.empty()) { 
            for( int i = 0 ; i < pq.top().first ; i++ ) { 
                ans += pq.top().second;
            }
            pq.pop();
        }
        return ans;
    }
};
