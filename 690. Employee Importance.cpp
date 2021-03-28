/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    map < int, Employee* > graph;
    
    int dfs( int id) {
        Employee* now = graph[id];
        int ans = now->importance;
        for( int x: now->subordinates) {
            ans += dfs( x);
        }
        return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {
        int sz = employees.size();
        for( int i = 0 ; i < sz ; i++ ) {
            graph[employees[i]->id] = employees[i];
        }
        return dfs(id);
    }
};
