bool cmp(vector<int> a, vector<int>b) { 
    if(a[0] == b[0] ) return a[1] > b[1];
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       
        int sz = intervals.size();
        if( sz == 0 ) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        vector < vector < int > > ans;
        vector < int > current;
        int lst = intervals[0][1];
        int fst = intervals[0][0];
        for( int i = 1 ; i < sz ; i++ ) { 
            if(lst >= intervals[i][0] ) { 
                lst = max(lst, intervals[i][1]);
                fst = min(fst, intervals[i][0]);
                
            } else {
                    current.push_back(fst);
                    current.push_back(lst);
                    ans.push_back(current);
                    lst = intervals[i][1];
                    fst = intervals[i][0];
                    current.clear();
                   
                
        }
    }

    current.push_back(fst);
    current.push_back(lst);
    ans.push_back(current);
    return ans;
    }
};
