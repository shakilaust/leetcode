class Solution {
public:
    int sFreq[256] = {0};
    int tFreq[256] = {0};
    bool isPresent[256] = {0};
    bool allEqual(){ 
         //debugPrint();
        for( int i = 0 ; i < 255 ; i++ ) if( tFreq[i] > 0 && tFreq[i] > sFreq[i] ) return false;
        return true;
    }
    string minWindow(string s, string t) {
        
        
        int low = 0, high = 0, sSz = s.size(), tSz = t.size(), minSoFar = -1, svLow, svHigh;
        for( int i = 0 ; i < tSz; i++ ) { 
            tFreq[t[i]]++;
            isPresent[t[i]] = 1;
        }
        while( high < sSz && isPresent[s[high]] == 0 ) { 
            high++;
            low++;
        }
        while( high < sSz ) { 
            sFreq[s[high]]++;
            while(allEqual()) { 
               // printf("all equal true min %d max %d\n", low, high);
               //  debugPrint();
                if( minSoFar == -1 || minSoFar > ( high - low + 1 ) ) { 
                    minSoFar = high - low + 1;
                    svLow = low;
                    svHigh = high;
                }
              //  printf("minSo far %d\n", minSoFar);
                sFreq[s[low]]--;
                low++;
                
            }
            high++;
        }
        
       

        string result = "";
        if( minSoFar != -1 ) {
            for( int i = svLow; i <= svHigh ; i++ ) result += s[i];
        }
        
        return result;
        
        
    }
};
