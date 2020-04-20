class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue < int > pq;
        unordered_map< char, int > freq;
        for( char task: tasks ) freq[task]++;
        for( pair< char, int> task: freq) { 
            pq.push(task.second);
        }

        int ans = 0;
        int cycle = n + 1;
        while(!pq.empty()) { 
            
            int newlyAdded = 0;
            vector < int > updatedTask;
            for( int i = 0 ; i < cycle && !pq.empty() ; i++ )  {
                
                newlyAdded++;
                updatedTask.push_back(pq.top());
                pq.pop();

            }

            for( int x: updatedTask ) { 
                if(--x) { 
                    pq.push(x);
                }
            }
            ans += !pq.empty() ? cycle : newlyAdded;

        }
        
        return ans;
    }
};
