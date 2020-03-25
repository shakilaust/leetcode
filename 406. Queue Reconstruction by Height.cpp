
bool cmp(vector < int > &a, vector < int > &b) { 

    if(a[0] == b[0] ) return a[1] < b[1];
    return a[0] > b[0];
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector < vector < int >  > ans;
        sort( people.begin(), people.end(), cmp);
        for( int i = 0 ; i < people.size() ; i++ ) { 
            ans.insert(ans.begin() + people[i][1], people[i]);
        }
        return ans;
    }
};
