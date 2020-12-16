bool cmp( vector< int> &a, vector < int > &b ) {
    return a[1] - a[0] > b[1] - b[0];
}


bool isPossible(vector< vector< int > > &tasks, int val ) {
    
    for( vector < int > task: tasks ) {
        if( task[1] > val ) return false;
        val -= task[0];
    }
    
    return true;
}


class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), cmp );
        int low = 0, high = 1e9;
        int sz = tasks.size();
        for( int i = 0 ; i < sz ; i++) {
            low = max( low, tasks[i][1] );
        }
        int ans = high;
    
        while( low <= high ) {
            int mid = low + ( high - low ) / 2;
            
            bool ok = true;
            int val = mid;
            for( int i = 0 ; i < sz ; i++ ) {
                if( tasks[i][1] > val ) {
                    ok = false;
                    break;
                }
                    val -= tasks[i][0];
            }
            if( ok ) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
};
