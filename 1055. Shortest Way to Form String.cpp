class Solution {
public:
    int shortestWay(string source, string target) {
        vector < int > pos[ 26 ];
        for( int i = 0 ; i < source.size() ; i++ ) { 
            pos[source[i] -'a'].push_back(i);
        }
        
        int prv = -1, ans = 1;
        for( int i = 0 ; i < target.size() ; i++ ) { 
            
            int now = target[i] - 'a';
            if(pos[now].size() == 0 ) return -1;
            bool notfound = true;
            while(notfound) {
                int low = lower_bound(pos[now].begin(), pos[now].end(), prv ) - pos[now].begin();
                int up = upper_bound(pos[now].begin(), pos[now].end(), prv ) - pos[now].begin();
              //  cout << " i " << i << " prv " << prv << " low " << low << " high " << up << endl;
                if(low == pos[now].size()) { 
                    prv = -1;
                    ans++;
                } else { 
                    
                    prv = pos[now][low] + 1;
                  
                    notfound = false;
                }
            }
            
        }
        
        return ans;
    }
};
