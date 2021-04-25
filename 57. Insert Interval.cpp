class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector < vector < int > > ans;
      
        int idx = 0;
        while( idx < intervals.size() && intervals[idx][1] < newInterval[0] ) {
            ans.push_back( intervals[idx] );
            idx++;
        }
        
        vector < int > add{ newInterval[0], newInterval[1] };
        while( idx < intervals.size() && intervals[idx][0] <= newInterval[1] ) {
            add[0] = min( intervals[idx][0], add[0] );
            add[1] = max( intervals[idx][1], add[1] );
            idx++;
        }
        
        ans.push_back( add );
        while( idx < intervals.size() ) {
            ans.push_back( intervals[idx++]);
        }
        
        return ans;
    }
};
