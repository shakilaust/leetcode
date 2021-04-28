const int NX = 1e4 + 10;
vector < int > graph[ NX ];
vector < bool > canBeRoot;
vector < bool > visits;

bool dfs( int x ) {
    visits[x] = true;

    for( int now: graph[x]) {
        if( visits[now] ) {
            return false;
        } else if( dfs( now ) == false ) {
            return false;
        }
        
    }
    return true;
}
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
         canBeRoot.resize(n, true);
         visits.resize(n, false);
         for( int i = 0 ; i < n; i++ ) {
             graph[i].clear();
             canBeRoot[i] = true;
             visits[i] = false;
         }
         for( int i = 0 ; i < n ; i++ ) {
             if( leftChild[i] != -1 ) {
                 canBeRoot[leftChild[i]] = false;
                 graph[i].push_back(leftChild[i]);
             }
             if( rightChild[i] != -1 ) {
                 canBeRoot[rightChild[i]] = false;
                 graph[i].push_back(rightChild[i]);
             }
         }
          int possibleRoot = -1;
        
          for( int i = 0 ; i < n ; i++ ) {
              cout << " canBeRoot " << i << " v " << canBeRoot[i] << endl;
              if( canBeRoot[i] && possibleRoot == -1 ) {
                  possibleRoot = i;
              } else if( canBeRoot[i] ) {
                  return false;
              }
          }
          if( possibleRoot == -1 ) {
              return false;
          }
        
        bool possibleAns = dfs( possibleRoot );
        for( int i = 0 ; i < n && possibleAns ; i++ ) {
            if( visits[i] == false ) {
                possibleAns = false;
            }
        }
        return possibleAns;
    }
};
