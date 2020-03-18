int minDistance( vector< int > list, int target ) { 
        
    int ans = 0;
    for( auto it: list ) { 
        ans += abs(target - it);
    }
    
    return ans;

}

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        vector < int > rowList, columnList;
        
        for( int i = 0 ; i < rows ; i++ ) { 

           for( int j = 0 ; j < columns ; j++ ) { 

                if(grid[i][j] == 1 ) rowList.push_back(i);
            }
        }

        for( int i = 0 ; i < columns ; i++ ) { 
            for( int j = 0 ; j < rows ; j++ ) { 

                if(grid[j][i] == 1 ) { 
                    columnList.push_back(i);
                  
                }
            }
        }
        
        int x = rowList[rowList.size() / 2 ];
        int y = columnList[ columnList.size() / 2];
    
        return minDistance(rowList, x ) + minDistance(columnList , y );
        
    }
};
