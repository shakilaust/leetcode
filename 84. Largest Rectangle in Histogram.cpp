class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        vector < int > left;
        int sz = heights.size();
        int mxHeight = 0;
        stack < int > pos;
        
        for( int i = 0 ; i < sz ; i++ ) { 
            while( !pos.empty() && heights[pos.top()] >= heights[i] ) { 
                pos.pop();
            }
            left.push_back( pos.empty() ? 0 : pos.top() + 1 );
            pos.push(i);
        }
        
       while( !pos.empty() ) pos.pop();

       for( int i = sz - 1 ; i >= 0 ; i--) { 
            while( !pos.empty() && heights[pos.top()] >= heights[i] ) { 
                pos.pop();
            }
            int rgt = pos.empty() ? sz - 1 : pos.top() - 1;
            int possibleRactagle = ( rgt - left[i] + 1 ) * heights[i];
            mxHeight = max( mxHeight, possibleRactagle );
            pos.push(i);
       }
        
       return mxHeight;
    }
};
