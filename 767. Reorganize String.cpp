class Solution {
public:
    string reorganizeString(string S) {
        priority_queue< pair< int, char> > pq;
        int freq[30] = {0};
        for( char ch: S) { 
            freq[ch - 'a']++;
        }
        
        for( int i = 0 ; i < 26 ; i++ ) { 
            if( freq[i] > 0 ) { 
                pq.push({freq[i], (char) i + 'a'});
            }
        }
        
        string ans = "";
        char prv = '%';
        while( !pq.empty() ) { 
            char used = pq.top().second;
            int cnt = pq.top().first;
            pq.pop();
            if( used != prv ) { 
                ans += used;
                if( cnt - 1 > 0 ) pq.push({ cnt - 1 , used } );
            } else {

                if( pq.empty() ) return "";
                char now = pq.top().second;
                int ccnt = pq.top().first;
                ans += now;
                pq.pop();
                if( ccnt - 1 > 0 ) pq.push({ ccnt - 1 , now });
                pq.push({ cnt , used } );
                used = now;
            }
            
            prv = used;
          //  cout << " prv " << prv << endl;
        }
        return ans;
    }
};
