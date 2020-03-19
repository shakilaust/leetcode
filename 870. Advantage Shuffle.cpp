
bool cmp(  pair < pair< int, int > , int > &a,  pair < pair< int, int > , int > &b) { 

    if(a.first.first == b.first.first ) return a.second > b.second;
    return a.first.first > b.first.first;
}

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector < pair < pair< int, int > , int >  > values;
        vector <int> ans(A);
        vector< int > taken( A.size() , 0 );
        for( int i = 0 ;  i < A.size() ; i++ ) { 
            values.push_back(make_pair(make_pair(A[i], i), 0));
        }
        
        for( int i = 0 ; i < B.size() ; i++ ) { 
             values.push_back(make_pair(make_pair(B[i], i), 1));
        }
        
        sort(values.begin(), values.end(), cmp);
        stack< pair< int, int> > st, lft;
        for( int i = 0 ; i < values.size() ; i++ ) { 
          //  cout <<" i " << i << " " << values[i].first.first <<  " " << values[i].first.second << endl;
            if( values[i].second == 0 ) { 
                st.push(values[i].first);
            } else { 
                
                if( !st.empty()) { 
                    ans[values[i].first.second] = st.top().first;
                    taken[st.top().second] = 1;
                    st.pop();
                } else { 
                    lft.push(values[i].first);
                }

            }
        }
        
        while( !lft.empty()) { 
            ans[lft.top().second] = st.top().first;
            st.pop();
            lft.pop();
        }
        
        
        return ans;
    }
};
