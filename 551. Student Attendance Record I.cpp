class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, continuousL = 0;
        for( int i = 0 ; i < s.size() ; i++ ) { 
          if( s[i] == 'L' ) continuousL++;
          else {
              continuousL = 0;
              if(s[i] == 'A' ) a++;

         }
            if( a > 1 || continuousL > 2 ) return false;
        
        }
        return true;
    }
};
