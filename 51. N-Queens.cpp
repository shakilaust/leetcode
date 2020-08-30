class Solution {
    vector < vector < string > > ans;
    vector < int > takenRows, takenCols;
    
public:
    bool isOk( int row, int col) {
        int sz = takenRows.size();
        for( int i = 0 ; i < sz ; i++ ) { 
            if( takenRows[i] == row || takenCols[i] == col ) return false;
            if( abs(takenRows[i] - row) ==  abs(takenCols[i] - col) ) return false;
        }
        
        return true;
    }
    void solve( int row, int col, int n, vector< string > &cur ) { 
      //  cout << " row " << row << " col " << col << " n " << n << endl;
        if( row >= n ) { 
           // cout << " now " << takenRows.size() << endl;
           if( takenRows.size() == n ) {
                 ans.push_back(cur);
           }
           
            return;
        }
        if( col >= n ) { 
            solve( row + 1 , 0 , n,  cur );
            return ;
        }
        
        if( isOk( row, col ) ) { 
            cur[row][col] = 'Q';
            takenRows.push_back(row);
            takenCols.push_back(col);
            solve( row + 1, 0 , n,  cur );
            takenRows.pop_back();
            takenCols.pop_back();
            cur[row][col] = '.';
        } 
        
        solve( row, col + 1 , n,  cur );
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector < string > cur;
        for( int i = 0 ; i < n ; i++ ) { 
            string now = "";
            for( int j = 0 ; j < n ; j++) now += '.';
            cur.push_back(now);
        }
        takenRows.clear();
        takenCols.clear();
        ans.clear();
        solve( 0 , 0 , n , cur );
        return ans;
    }
};
