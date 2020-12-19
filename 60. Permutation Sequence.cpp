
bool taken[10] = {false};
int fact[10];
int mx;
string dfs(int rem, int k) {
    if( rem == 0 ) return "";
    int add = fact[rem - 1];
   // cout << " rem " << rem << " add " << add << endl;
    int soFar = 0;
    int willTake = -1;
    for( int i = 1 ; i <= 9 ; i++ ) {
        if( taken[i] ) continue;
        if( soFar + add >= k ) {
            willTake = i;
            break;
        }
        soFar += add;
       // cout << " i " << i << " sofar " << soFar << endl;
    }
    taken[willTake] = true;
    return to_string(willTake) + dfs( rem - 1, k - soFar );
}

class Solution {
public:
    string getPermutation(int n, int k) {
        fact[0] = 1;
        for( int i = 1 ; i <= 8 ; i++ ) {
            fact[i] = fact[i-1] * i ;
        }
        for(int i = 1 ; i <= n ; i++ ) {
            taken[i] = false;
        }
        return dfs( n, k );
    }
};
