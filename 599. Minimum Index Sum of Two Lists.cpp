class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map < string, int > isPresent;
        int idx = 0;
        for( string inp: list1) {
            isPresent[inp] = idx;
            idx++;
        }
        vector < string > answer;
        int mn = -1;
        idx = 0;
        for( string inp: list2) {
            if(isPresent.find(inp) != isPresent.end()) {
                int now = idx + isPresent[inp];
                if( mn == -1 || now < mn ) {
                    answer.clear();
                    answer.push_back(inp);
                    mn = now;
                } else if( mn != -1 && now == mn ) {
                    answer.push_back(inp);
                }
            }
            idx++;
        }
        
        return answer;
    }
};
