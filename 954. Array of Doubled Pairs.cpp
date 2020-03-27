bool cmp( int a, int b ) { 

    return abs(a) < abs(b);
}

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
     unordered_map<int, int> freq;
      sort( A.begin(), A.end() , cmp );
      for( int i = 0 ; i < A.size() ; i++ )  { 

            freq[A[i]]++;
      }
        
      for( int i = 0 ; i < A.size() ; i++ ) { 
          if(freq[A[i]] == 0 ) continue;
          int mn = freq[A[i]];
        //  cout << " mn " << mn << " values " << A[i] << endl;
          if( freq[ 2 * A[i]] < mn ) return false;
          freq[ 2 * A[i] ] -= mn;
          freq[ A[i] ] -= mn;

        }
        
    
    return true;
    }
};
