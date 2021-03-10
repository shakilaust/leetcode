




class Solution {
public:
    unordered_map< string, multiset< string > > graph;
    map< pair< string, string > , bool > visit;
    vector < string > answer;
    void dfs( string now) {
       
        while(!graph[now].empty()) {
            string nxt = *graph[now].begin();
            graph[now].erase(graph[now].begin());
            dfs(nxt);
        }
        answer.push_back(now);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
      
        int sz = tickets.size();
        for(vector< string > inp: tickets) {
            string from = inp[0];
            string to = inp[1];
            graph[from].insert(to);
       
        }
        
      
        dfs("JFK");
        reverse(answer.begin(), answer.end());

        return answer;
    }
};
