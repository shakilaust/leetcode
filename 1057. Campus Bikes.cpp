bool cmp( pair < int , pair< int, int > > a , pair < int , pair< int, int > > b ) {
    if( a.first == b.first ) {
        if( a.second.first == b.second.first ) {
            return a.second.second < b.second.second;
        }
        return a.second.first < b.second.first;
    }
    return a.first < b.first;
}

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector < pair< int, pair< int, int > >> dis;
        int wSz = workers.size();
        vector < int > ans( wSz , -1);
       
        int bSz = bikes.size();
         vector < int > taken( bSz , -1 );
        for( int i = 0 ; i < wSz ; i++ ) { 
            for( int j = 0 ; j < bSz ; j++ ) { 
                int d = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                dis.push_back(make_pair( d , make_pair( i , j ) ) );
            }
        }

        sort(dis.begin(), dis.end(), cmp );
        int sz = dis.size();
        for( int i = 0 ; i < sz && wSz ; i++ ) { 
            int w = dis[i].second.first;
            int b = dis[i].second.second;
            if( ans[w] == -1 && taken[b] == -1 ) { 
                ans[w] = b;
                taken[b] = w;
                wSz--;
            }
        }
        
        return ans;
    
    
    }
};
