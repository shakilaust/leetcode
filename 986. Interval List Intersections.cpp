class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector< vector< int > > ans;
        vector < int > tmp;
        int aIdx = 0, bIdx = 0;
        while(aIdx < A.size() && bIdx < B.size()) { 
            int start = max(A[aIdx][0], B[bIdx][0]);
            int end = min(A[aIdx][1], B[bIdx][1]);
            if( end - start >= 0 ) { 
                tmp.clear();
                tmp.push_back(start);
                tmp.push_back(end);
                ans.push_back(tmp);
            }
            
            if(A[aIdx][1] < B[bIdx][1] ) aIdx++;
            else bIdx++;
        }
        
        return ans;
    }
};
