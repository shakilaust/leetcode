class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        queue< pair< int, int > > q;
        int curColor = image[sr][sc];
        if( curColor == newColor ) return image;
        q.push(make_pair(sr, sc) );
        image[sr][sc] = newColor;
        int mxX = image.size();
        int mxY = image[0].size();
        while(!q.empty()) {
            pair< int, int > cur = q.front();
            q.pop();
            int cx = cur.first;
            int cy = cur.second;
            for( int i = 0 ; i < 4; i++ ) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if( nx >= 0 && nx < mxX && ny >= 0 && ny < mxY && curColor == image[nx][ny] ) { 
                    image[nx][ny] = newColor;
                    q.push(make_pair(nx, ny));

                }
            }

        }
        return image;
    }
};
