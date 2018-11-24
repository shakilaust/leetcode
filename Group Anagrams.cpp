class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         int hashPrime[26];
         int nextPossiblePrime = 2;
         for( int i = 0 ; i < 26 ; i++ ) {
             bool isPrime = false;
             while(isPrime == false) { 
                isPrime = true;
                for( int i = 2 ; i * i <= nextPossiblePrime && isPrime; i++ ) { 
                    if( nextPossiblePrime % i == 0 ) { 
                        isPrime = false;
                    }
                }
                if( isPrime ) break;
                nextPossiblePrime += 1;
            }
            hashPrime[i] = nextPossiblePrime;
            nextPossiblePrime += 1;
          }
        vector < vector < string > > answer;
        map < int , int > hashIdx;
        int sz = strs.size();
        int idx = 0;
        for( int i = 0 ; i < sz ; i++ ) { 
            int hashValue = 1;
            int strSz = strs[i].size();
            for( int j = 0 ; j < strSz ; j++ ) { 
                hashValue = hashValue * hashPrime[strs[i][j] - 'a'];
            }
            if( hashIdx.find(hashValue) == hashIdx.end()) { 
                vector < string > newIdxStart;
                newIdxStart.push_back(strs[i]);
                answer.push_back(newIdxStart);
                hashIdx[hashValue] = idx++;
            } else {
                int existsIdx = hashIdx[hashValue];
                answer[existsIdx].push_back(strs[i]);

            }
        }
        return answer;
    }
};
