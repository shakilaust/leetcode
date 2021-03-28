class Solution {
public:
    int integerReplacement(int n) {
        queue < long long int > q, cost;
        q.push(n);
        cost.push(0);
        int ans = -1;
        unordered_map<long long int, bool> visit;
        visit[n] = true;
        while( !q.empty()) {
            long long int now = q.front();
            int c = cost.front();
            if( now == 1 ) {
                ans = c;
                break;
            }
            q.pop();
            cost.pop();
            if( now % 2 == 0 ) { 
                if( visit[now/2] != true ) {
                    visit[now/2] = true;
                    q.push(now/2);
                    cost.push(c + 1);
                    
                }
            } else {
                if( visit[now - 1] != true ) {
                    visit[now-1] = true;
                    q.push( now -1 );
                    cost.push(c + 1);
                } 
                if( visit[now + 1] != true ) {
                    visit[now + 1] = true;
                    q.push( now + 1 );
                    cost.push( c + 1 );
                }
            }
            
            
        }
        return ans;
    }
};
