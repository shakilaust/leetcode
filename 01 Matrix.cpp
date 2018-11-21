#include <bits/stdc++.h>
using namespace std;

int dx[] =  { 1, -1 , 0, 0 };
int dy[] = { 0 , 0 , 1 , -1 };

vector< vector< int> > vis;
vector < int > tmp;
queue < int > x , y, cost;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vis.clear();
        int row = matrix.size();
        int column = matrix[0].size();
        for( int i = 0 ; i < row ; i++ ) {
            tmp.clear();
            for( int j = 0 ; j < column; j++ ) { 
                tmp.push_back(0);
            }
            vis.push_back(tmp);
        }
        
        for( int i = 0 ; i < row ; i++ ) {
            for( int j = 0 ; j < column; j++ ) { 
                if( matrix[i][j] == 0 ) {
                    x.push(i);
                    y.push(j);
                    cost.push(0);
                    vis[i][j] = 1;
                }
            }
        }
        
        while(!x.empty()) { 
            int currentX = x.front();
            int currentY = y.front();
            int currentCost = cost.front();
            x.pop();
            y.pop();
            cost.pop();
            for( int i = 0 ; i < 4 ; i++ ) { 
                int nxt_x = currentX + dx[i];
                int nxt_y = currentY + dy[i];
                if( nxt_x >= 0 && nxt_x < row && nxt_y >= 0 && nxt_y < column && vis[nxt_x][nxt_y] == 0) { 
                    int nxt_cost = currentCost + 1;
                    x.push(nxt_x);
                    y.push(nxt_y);
                    cost.push(nxt_cost);
                    matrix[nxt_x][nxt_y] = nxt_cost;
                    vis[nxt_x][nxt_y] = 1;
                }
                
            }
        }
        return matrix;
        
    }
    
};
