class Solution {
    
void dfs( int curValue, int n, vector < int > &ans ) { 
    if( curValue <= n ) { 

        ans.push_back(curValue);
        for( int i = 0 ; i < 10 ; i++ ) { 
            if( curValue * 10 + i > n ) return;
            dfs( curValue * 10 + i , n,  ans );
        }
    }
}
public:
    vector<int> lexicalOrder(int n) {
        vector < int > ans;
        for( int i = 1 ; i < 10 ; i++ ) { 
            dfs( i , n, ans );
        }
        
        return ans;
    }
};
