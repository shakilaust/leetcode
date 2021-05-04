class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
      vector < vector < int > > ans;
      int rows = image.size();
      if( rows == 0 ) {
          return ans;
      }
      int cols = image[0].size();
      for( int row = 0 ; row < rows ; row++ ) {
            vector < int > add;
            for( int col = cols - 1 ; col >= 0 ; col-- ) {
                add.push_back( !image[row][col]);
            }
          ans.push_back(add);
     }
     
    return ans;
    }
};
