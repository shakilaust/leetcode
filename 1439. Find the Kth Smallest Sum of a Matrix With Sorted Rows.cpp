class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
       set < pair < int, vector<int> > > s;
       pair < int, vector < int > > elements;
        for( int i = 0 ; i < mat.size() ; i++ ) {
            elements.second.push_back(0);
            elements.first += mat[i][0];
        }
        if( k == 1 ) {
            return elements.first;
        }
        s.insert(elements);
        while( k > 1 ) {
            auto iter = s.begin();
            pair < int, vector < int > > now = (*iter);
            s.erase(iter);
            for( int i = 0 ; i < mat.size() ; i++ ) {
                if( now.second[i] + 1 < mat[i].size() ) {
                    now.first += ( mat[i][now.second[i] + 1 ] - mat[i][now.second[i]]);
                    now.second[i]++;
                    s.insert( now );
                    now.second[i]--;
                    now.first += ( mat[i][now.second[i]] - mat[i][now.second[i] + 1]);
                }
            }
            k--;
        }
        auto temp = s.begin();
        int ans= (*temp).first;
        return ans;
    }
};
