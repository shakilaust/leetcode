
bool isPossible( string a, string b ) { 
    
    if( a.size() != b.size() ) return false;
    int change = 0;
    for( int i = 0 ; i < a.size() ; i++ ) { 
        if( a[i] != b[i] ) change++;
        if( change > 1 ) return false;
    }
    
    if( change <= 1 ) return true;
    return false;
}

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int sz = wordList.size();
        bool found = false;
        for( int i = 0 ; i < sz && !found ; i++ ) { 
            if( wordList[i] == endWord ) found = true;
        }
        
       
        if( found == false ) return 0;
        
        queue < string > q;
        queue < int > cost;
        vector < bool > visit( sz + 1 , false );
      
        q.push(beginWord);
        cost.push(1);
        
        while( !q.empty()) { 

            string now = q.front();
            int currentCost = cost.front();
         
          
            q.pop();
            cost.pop();
            for( int i = 0 ; i < sz ; i++ ) { 
                if( wordList[ i ] == now ) continue;
                if( visit[i ] ) continue;
                if( isPossible(wordList[i], now ) ) { 
                    if( wordList[i] == endWord ) return currentCost + 1;
                    q.push( wordList[i] );
                    cost.push( currentCost + 1 );
                    visit[ i ] = true;
                }
            }
        }
        return 0;
        
    }
};
